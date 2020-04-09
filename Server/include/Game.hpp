/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Game.hpp
*/

#pragma once

#include "Entity.hpp"

class Game
{
  private:
    std::vector<Entity> objects;
  public:
    Game() {};
    ~Game() {};
    std::vector<Entity> &getObjects() {
      return (objects);
    };
};
