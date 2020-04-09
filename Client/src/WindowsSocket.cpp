/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** WindowsSocket.cpp
*/

#ifdef _WIN32

#include "WindowsSocket.hpp"

Socket::Socket(const std::string &ip, char *port, int side)
{
  int p = std::stoi(port);
  this->_len = sizeof(this->_client);
  this->_server.sin_family = AF_INET;
  this->_server.sin_port = htons(p);
  this->_server.sin_addr.s_addr = inet_addr(ip.c_str());
  std::cout << "[WINDOWS]" << std::endl;
  if (WSAStartup(MAKEWORD(2, 2), &_wsa) != 0) {
    std::cout << "Error Code :" << WSAGetLastError() << std::endl;
    throw this->_exception;
  }
}

Socket::~Socket()
{
  WSACleanup();
  shutdown(this->_socket, 2);
  closesocket(this->_socket);
}

bool Socket::openSocket()
{
  if ((this->_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
    throw this->_exception;
    return false;
  }
  return true;
}

bool Socket::bindSocket()
{
  if (bind(this->_socket, (struct sockaddr *)&_server, sizeof(this->_server)) == -1) {
    wprintf(L"bind failed with error %u\n", WSAGetLastError());
    closesocket(this->_socket);
    WSACleanup();
    return false;
  }
  return true;
}

Packet *Socket::recvPacket()
{
  int rcvLen = 0;
  if ((rcvLen = recvfrom(this->_socket, this->_buf, BUFLEN, 0, (struct sockaddr *)&this->_client, &this->_len)) == -1)
    throw this->_exception;
  return new Packet(this->_buf, rcvLen, this->_client);
}

bool Socket::sendPacket(void* data, std::size_t len)
{
  int sendLen = 0;
  if ((sendLen = sendto(this->_socket, (char *)data, len, 0, (struct sockaddr *)&this->_server, this->_len)) == -1)
    return false;
  return true;
}

int Socket::getSocket()
{
  return this->_socket;
}

void Socket::setDest(struct sockaddr_in& dest)
{
  this->_server = dest;
}
#else
#endif
