/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** ClientManager.cpp
*/

#include <iostream>
#include "ClientManager.hpp"
#include "Room.hpp"

ClientManager::ClientManager(std::vector<Client> &clients, RoomManager &rooms) : _clientList(clients) , _rooms(rooms)
{
  this->_nbClient = 0;
  std::cout << "Manager client created." << std::endl;
}

ClientManager::~ClientManager()
{
}

int ClientManager::getNbClient()
{
  return this->_nbClient;
}

void ClientManager::setNbClient(int i)
{
  this->_nbClient += i;
}

RoomManager &ClientManager::getRoomManager() const
{
  return this->_rooms;
}

void ClientManager::verifIfCreateARoom()
{
  std::cout << "Number of Client in the Manager: " << this->getNbClient() << std::endl;
  if (this->getNbClient() >= 4) {
    std::cout << "Need to create a new room." << std::endl;
    this->getRoomManager().createRoom(this->_clientList);
    for (int i = 0; i < 4; i++)
      this->removeClientList();
  }
}

int ClientManager::addClientList(Client &client)
{
  this->_clientList.push_back(client);
  this->setNbClient(1);
  this->verifIfCreateARoom();
  return (0);
}

int ClientManager::removeClientList()
{
  this->setNbClient(-1);
  this->_clientList.pop_back();
  return (0);
}