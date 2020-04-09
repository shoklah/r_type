/*
** EPITECH PROJECT, 2020
** Rtype
** File description:
** main.cpp
*/

#include <ctype.h>
#include <string.h>
#include <iostream>
#include <stdexcept>
#include "Server.hpp"
#include "ClientManager.hpp"

int main(int ac, char **av)
{
  if (ac != 3) {
    std::cout << "Usage : ./r-type_server Ip Port" << std::endl;
    return (1);
  }
  try {
    std::vector<Client> clients;
    Socket socket(av[1], av[2], SERVER);
    RoomManager manageRoom(socket);
    ClientManager manageClient(clients, manageRoom);
    Server srv(socket, manageClient);
    if (socket.openSocket() == false)
      std::cout << "[ERROR] Socket open." << std::endl;
    if (socket.bindSocket() == false)
      std::cout << "[ERROR] Socket bind." << std::endl;
    srv.run();
  } catch (const std::invalid_argument &ia) {
    std::cerr << "[ERROR] Wrong port." << std::endl;
  }
  return (0);
}