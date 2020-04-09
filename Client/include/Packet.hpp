/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Packet.hpp
*/

#pragma once
#include <iostream>
#include <sys/types.h>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#endif

class Packet {
  public:
    Packet(char *buf, int len, struct sockaddr_in client) :  _client(client), _buf(buf), _len(len) {}
    ~Packet() = default;
    std::string getBuf();
    char *getBufChar();
    int getLen() const;
    struct sockaddr_in  getClientIp() const;
  private:
    struct sockaddr_in _client;
    char *_buf;
    int _len;
};