/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** PacketManager.hpp
*/

#pragma once

#include <iostream>
#include <memory>
#include "../../Client/include/Data.hpp"
#include "../../Client/include/Packet.hpp"
#ifdef _WIN32
#include "../../Client/include/WindowsSocket.hpp"
#else
#include "../../Client/include/UnixSocket.hpp"
#endif
#include "ClientManager.hpp"

class PacketManager
{
  private:
    Socket &_socket;
    ClientManager &_clientM;
    void (PacketManager::*f[15])(std::shared_ptr<Packet> p);
    char _opcodes[15];
    void _key(std::shared_ptr<Packet> p);
    void _handShake(std::shared_ptr<Packet> p);
  public:
    PacketManager(Socket &_s, ClientManager &c);
    ~PacketManager();
    void handlePacket(std::shared_ptr<Packet> p);
};