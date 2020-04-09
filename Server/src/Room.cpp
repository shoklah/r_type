/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Room.cpp
*/

#include <iostream>
#include "Room.hpp"
#include <thread>
#include <mutex>
#include <algorithm>
#include <memory>
#include "../../Client/include/Data.hpp"
#include "Game.hpp"
#include "Entity.hpp"

std::mutex mymutex;

Room::Room(int id, std::vector<Client> listClient, Socket &s) : _socket(s)
{
  this->_id = id;
  for (unsigned int i = 0; i < listClient.size(); ++i) {
    listClient[i].getPlayer().setPosY(listClient[i].getPlayer().getPosY() * (i + 1));
    listClient[i].getPlayer().setId(listClient[i].getPlayer().getId() + i);
    this->_client.push_back(listClient[i]);
    std::cout << "Client[" << listClient[i].getPlayer().getId() << "] posY = " << listClient[i].getPlayer().getPosY() << std::endl;
  }
  std::cout << "New Room[" << this->getId() << "] create" << std::endl;
}

Room::~Room()
{
  std::cout << "Room deleted." << std::endl;
}

int Room::getId()
{
  return this->_id;
}

void Room::setId(int val)
{
  this->_id = val;
}

std::shared_ptr<std::thread> Room::spawnThread()
{
  std::shared_ptr<std::thread> t = std::make_shared<std::thread>([this]() {
    std::cout << "Thread launched." << std::endl;
    std::chrono::milliseconds Interval(200);
    newGame_t ng;
    int i = 1;
    for (Client &c : this->_client) {
      ng.opcode = 0x0C;
      ng.id = i;
      this->_socket.setDest(c.getIp());
      if (this->_socket.sendPacket(&ng, sizeof(newGame_t)) == true) {
        std::cout << "startGame sent (0x0C)" << std::endl;
      } else {
        std::cout << "Send failed." << std::endl;
      }
      i++;
    }

    std::vector<Entity> objects;
    objects.push_back(Entity(1, 1, 200, 90));
    objects.push_back(Entity(2, 1, 200, 270));
    objects.push_back(Entity(3, 1, 200, 450));
    objects.push_back(Entity(4, 1, 200, 630));
    int nbEnemies = 5;
    while (true) {
      int idmsg = 0;
      int Movement = 0;
      std::lock_guard<std::mutex> guard(mymutex);
      if (_instruction.size() != 0) {
        struct t_key *msgEvent = reinterpret_cast<struct t_key *>((char *)_instruction.at(0));
        idmsg = msgEvent->Playerid;
        Movement = msgEvent->key;
        _instruction.erase(_instruction.begin());
        std::cout << "i received msg from " << idmsg << " key: " << Movement << std::endl;
      }
      if (Movement == 5) {
        for (Entity &tmp : objects) {
          if (idmsg == tmp.getId())
            objects.push_back(Entity(objects.size() + 1, 2, tmp.getX(), tmp.getY() + 200));
        }
      }
      while(nbEnemies < 8) {
        objects.push_back(Entity(objects.size() + 1, 3, 800, 75 * nbEnemies));
        nbEnemies++;
      }
      for (Entity &tmp : objects) {
        if (tmp.getCreated() == 0) {
          create_t start;
          for (Client &c : this->_client) {
            start.opcode = 0x01;
            start.idEntity = tmp.getId();
            start.typeEntity = tmp.getType();
            start.x = tmp.getX();
            start.y = tmp.getY();
            this->_socket.setDest(c.getIp());
            if (this->_socket.sendPacket(&start, sizeof(create_t)) == true)
              std::cout << "newEntity sent (0x01)" << std::endl;
            else
              std::cout << "Send failed." << std::endl;
          }
          tmp.setCreated(1);
          std::cout << "Created = " << tmp.getCreated() << " 0X01 " << tmp.getId() << " " << tmp.getX() << " " << tmp.getY() << std::endl;
        }
      }

      for (Entity &tmp : objects) {
        if (tmp.getType() == 1 && tmp.getId() == idmsg) {
          tmp.moveEntity(Movement);
        } else {
          tmp.moveEntity(0);
        }
        if (tmp.getCreated() == 1) {
          move_t move;
          for (Client &c : this->_client) {
            move.opcode = 0x02;
            move.idEntity = tmp.getId();
            move.x = tmp.getX();
            move.y = tmp.getY();
            this->_socket.setDest(c.getIp());
            if (this->_socket.sendPacket(&move, sizeof(move_t)) == true)
              std::cout << "MoveEntity sent (0x02)" << std::endl;
            else
              std::cout << "Send failed." << std::endl;
          }
          std::cout << " 0X02 " << tmp.getId() << " " << tmp.getX() << " " << tmp.getY() << std::endl;
        }
      }

      for (Entity &it : objects) {
        if (it.ColisionCheck(objects) == 1) {
          if (it.getCreated() == 1) {
            die_t die;
            for (Client &c : this->_client) {
              die.opcode = 0x03;
              die.idPlayer = it.getId();
              this->_socket.setDest(c.getIp());
              if (this->_socket.sendPacket(&die, sizeof(die_t)) == true) {
                std::cout << "RemoveEntity sent (0x03)" << std::endl;
              } else {
                std::cout << "Send failed." << std::endl;
              }
            }
            std::cout << " 0x03 " << it.getId() << std::endl;
            if (it.getType() == 3) {
              nbEnemies--;
            }
            int end = 0;
            for(std::vector<Entity>::iterator jetest = objects.begin(); jetest!= objects.end() && end != 1; ++jetest) {
              if (jetest->getId() == it.getId()) {
                objects.erase(jetest);
                end = 1;
              }
            }
          }
        }
      }
      std::cout << "Instruction size: " << this->_instruction.size() << std::endl;
    }
  });
  return (t);
}

void Room::pushInstruction(char* msg)
{
  this->_instruction.push_back(msg);
}

bool Room::isClient(const struct sockaddr_in &client)
{
  for (Client &value : this->_client) {
    if (value.getIp().sin_port == client.sin_port && value.getIp().sin_family == client.sin_family)
      return (true);
    }
  return (false);
}