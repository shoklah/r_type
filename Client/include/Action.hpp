/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Action.hpp
*/

#pragma once
#include "../../GameEngine/include/World.hpp"
#ifdef _WIN32
#include "WindowsSocket.hpp"
#else
#include "UnixSocket.hpp"
#endif
#include "EntityContainer.hpp"

class Action{
  public:
    Action(Socket &s, std::shared_ptr<EntityContainer> a);
    ~Action();

    void ActionOnKey(const eAction &action);
  private:
    Socket  &_socket;
    std::shared_ptr<EntityContainer> _entityContainer;
    int _inc = 0;
};