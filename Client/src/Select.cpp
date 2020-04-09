/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Select.hpp
*/

#include "Select.hpp"
#include <iostream>
#ifdef _WIN32
#define IOCTL ioctlsocket
#include <winioctl.h>
#else
#define IOCTL ioctl
#include <sys/ioctl.h>
#endif

Select::Select(int socket)
{
  int rc  = IOCTL(socket, FIONBIO, &on);
  if (rc < 0) {
    std::cout << "ioctl error" << std::endl;
  }
}

Select::~Select()
{
}

void Select::mySelect(int socket)
{
  FD_ZERO(&_read_fds);
  FD_SET(socket, &_read_fds);
  int n = select(socket + 1, &_read_fds, &_write_fds, NULL, NULL);
  if (n < 0) {
    std::cout << "error select" << std::endl;
    return;
  }
}

bool Select::isNewMsg(int socket)
{
  if (FD_ISSET(socket, &_read_fds))
    return true;
  else
    return false;
}