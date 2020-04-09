/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** RoomManger.hpp
*/

#pragma once

#include <vector>
#include <sys/types.h>
#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#endif
#include "Room.hpp"
#include "../../Client/include/UnixSocket.hpp"

class RoomManager
{
  private:
    Socket &_socket;
    std::vector<std::shared_ptr<Room>> _roomList;
    std::vector<std::shared_ptr<std::thread>> _threadList;
  public:
    RoomManager(Socket &s);
    ~RoomManager();
    std::vector<std::shared_ptr<Room>> getRoomList();
    void createRoom(std::vector<Client>);
    void deleteRoom(int);
    std::shared_ptr<Room> getRoomFromClient(const struct sockaddr_in &);
};