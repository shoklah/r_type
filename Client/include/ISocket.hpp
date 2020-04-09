/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** ISocket.hpp
*/

#pragma once
#include "Packet.hpp"
#define BUFLEN 512
#define SERVER 0
#define CLIENT 1

class ISocket
{
  public:
    ~ISocket(){};

    virtual bool openSocket() = 0;
    virtual bool bindSocket() = 0;
    virtual Packet* recvPacket() = 0;
    virtual bool sendPacket(void *, std::size_t) = 0;
};