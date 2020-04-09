/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** RoomManger.cpp
*/

#include <vector>
#include <thread>
#include <mutex>
#include "RoomManager.hpp"
#include "RoomException.hpp"

int idRoom = 0;

RoomManager::RoomManager(Socket &s) : _socket(s)
{
  std::cout << "Manager room created." << std::endl;
}

RoomManager::~RoomManager()
{
}

std::vector<std::shared_ptr<Room>> RoomManager::getRoomList()
{
  return this->_roomList;
}

void RoomManager::createRoom(std::vector<Client> listClient)
{
  if (idRoom < 4) {
    std::cout << "Create new Room in Manager." << std::endl;
    std::shared_ptr<Room> room = std::make_shared<Room>(idRoom, listClient, this->_socket);
    std::shared_ptr<std::thread> t;
    t = room->spawnThread();
    t->detach();
    this->_threadList.push_back(t);
    idRoom++;
    this->_roomList.push_back(room);
  } else
    std::cout << "[ERROR] Room not created." << std::endl;
}

void RoomManager::deleteRoom(int id)
{
  static_cast<void>(id);
  for (std::shared_ptr<std::thread> value : this->_threadList) {
    if (value->joinable()) {
      std::cout << "Joined." << std::endl;
      value->join();
    }
  }
}

std::shared_ptr<Room> RoomManager::getRoomFromClient(const struct sockaddr_in &client)
{
  for (std::shared_ptr<Room> value : this->_roomList) {
    if (value->isClient(client) == true) {
      std::cout << "Client found." << std::endl;
      return value;
    }
  }
  throw RoomException();
}