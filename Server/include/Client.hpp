/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Client.hpp
*/

#pragma once

#ifdef _WIN32
#include <winsock2.h>
#else
#include <netinet/ip.h>
#include "../../Client/include/UnixSocket.hpp"
#endif
#include "Player.hpp"

class Client
{
  private:
    Player _player;
    struct sockaddr_in _ip;
  public:
    Client(struct sockaddr_in);
    ~Client();
    Player getPlayer();
    void setPlayer(Player);
    struct sockaddr_in& getIp();
    void setIp(struct sockaddr_in);
};