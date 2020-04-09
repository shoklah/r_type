/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** WindowsSocket.hpp
*/

#pragma once
#ifdef _WIN32

#include <ws2tcpip.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <functional>
#include <string>
#include "ISocket.hpp"
#include "NetException.hpp"

int runClient(const std::string &ip, int port);

class Socket : public ISocket
{
  public:
    Socket(const std::string &ip, char *port, int side);
    virtual ~Socket();

    virtual bool openSocket() final;
    virtual bool bindSocket() final;
    virtual Packet *recvPacket() final;
    virtual bool sendPacket(void* data, std::size_t len) final;
    int getSocket();
    void setDest(struct sockaddr_in& dest);
  private:
    NetException _exception;
    struct sockaddr_in _dest;
    struct sockaddr_in _server;
    struct sockaddr_in _client;
    char _buf[BUFLEN];
    socklen_t _len;
    SOCKET _socket;
    WSADATA _wsa;
};

#else
#endif