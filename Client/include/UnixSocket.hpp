/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** UnixSocket.hpp
*/

#pragma once
#ifdef _WIN32
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <functional>
#include "ISocket.hpp"
#include "NetException.hpp"

class Socket : public ISocket
{
  public:
    Socket(const std::string &ip, char *port, int side);
    virtual ~Socket();

    virtual bool openSocket() final;
    virtual bool bindSocket() final;
    virtual Packet* recvPacket() final;
    virtual bool sendPacket(void *data, std::size_t len) final;
    int getSocket();
    void setDest(struct sockaddr_in &dest);
  private:
    NetException _exception;
    struct sockaddr_in _server;
    struct sockaddr_in _client;
    struct sockaddr_in _dest;
    char _buf[BUFLEN];
    socklen_t _len;
    int _socket;
    int _port;
};

#endif