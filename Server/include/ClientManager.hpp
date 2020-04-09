/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** ClientManager.hpp
*/

#pragma once

#include <vector>
#include "Client.hpp"
#include "RoomManager.hpp"

class ClientManager
{
  private:
    std::vector<Client> &_clientList;
    int _nbClient;
    RoomManager &_rooms;
  public:
    ClientManager(std::vector<Client>&, RoomManager&);
    ~ClientManager();
    int getNbClient();
    void setNbClient(int);
    RoomManager& getRoomManager() const;
    int addClientList(Client&);
    int removeClientList();
    void verifIfCreateARoom();
};