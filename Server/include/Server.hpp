/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Server.hpp
*/

#pragma once
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <memory>
#include <vector>

#ifdef _WIN32
#include "../../Client/include/WindowsSocket.hpp"
#else
#include "../../Client/include/UnixSocket.hpp"
#endif

#include "ClientManager.hpp"
#include "Client.hpp"
#include "Room.hpp"
#include "PacketManager.hpp"

class Server
{
  public:
    Server(Socket &socket,ClientManager &clientM);
    ~Server();
    void run();
    void handleMsg(std::shared_ptr<Packet> p);
  private:
    Socket &_socket;
    ClientManager &_clientM;
    std::vector<Client> _clients;
    std::vector<Room> _rooms;
    std::shared_ptr<PacketManager> _packetManager;
};