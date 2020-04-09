/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Packet.cpp
*/

#include "Packet.hpp"

std::string Packet::getBuf()
{
  return this->_buf;
}

int Packet::getLen() const
{
  return this->_len;
}

struct sockaddr_in  Packet::getClientIp() const
{
  return this->_client;
}

char *Packet::getBufChar()
{
  return this->_buf;
}