/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Select.hpp
*/

#pragma once
#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#define STYPE DWORD
#else
#define STYPE int
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#endif
#include <sys/types.h>

class Select
{
  public:
    Select(int socket);
    ~Select();

    void mySelect(int socket);
    bool isNewMsg(int socket);
  private:
    fd_set _read_fds;
    fd_set _write_fds;
	STYPE on = 1;
};