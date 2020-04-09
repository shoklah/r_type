/*
** EPITECH PROJECT, 2020
** Rtype
** File description:
** main.cpp
*/

#include <ctype.h>
#include <string.h>
#include <memory>

#ifdef _WIN32
#include <winsock2.h>
#include "WindowsSocket.hpp"
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "UnixSocket.hpp"
#endif

#include <sys/types.h>

#include "Data.hpp"

#include "../../GameEngine/include/World.hpp"
#include "Game.hpp"

int main(int ac, char **av)
{
  if (ac != 3) {
    std::cout << "Usage : ./r-type_client Ip Port" << std::endl;
    return (1);
  } try {
    Socket socket(av[1], av[2], 1);
    if (socket.openSocket() == false)
      std::cout << "[ERROR] Open." << std::endl;
    connection_t t;
    t.opcode = 0x0A;
    if (socket.sendPacket(&t, sizeof(connection_t)) == true) {
      std::cout << "Message sent." << std::endl;
    }
    Game g(socket);
    g.connection();
    g.play();
  } catch (const std::invalid_argument &ia) {
    std::cerr << "[ERROR] Wrong port.\n";
  }
  return (0);
}
