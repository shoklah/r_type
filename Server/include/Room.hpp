/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Room.hpp
*/

#pragma once

#include <vector>
#include <thread>
#include "Client.hpp"
#ifdef _WIN32
#include "../../Client/include/WindowsSocket.hpp"
#else
#include "../../Client/include/UnixSocket.hpp"
#endif

class Room
{
  private:
    Socket &_socket;
    int _id;
    std::vector<Client> _client;
    std::vector<char*> _instruction;
  public:
    Room(int, std::vector<Client>, Socket&);
    ~Room();
    int getId();
    void setId(int);
    void deleteClientToRoom(Client);
    std::shared_ptr<std::thread> spawnThread();
    void stopRoom();
    void pushInstruction(char*);
    bool isClient(const struct sockaddr_in &client);
};