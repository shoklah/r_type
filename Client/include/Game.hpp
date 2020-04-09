/*
** EPITECH PROJECT, 2020
** Rtype
** File description:
** Game.hpp
*/

#pragma once
#include <thread>
#include <memory>
#include "../../GameEngine/include/World.hpp"
#ifdef _WIN32
#include "WindowsSocket.hpp"
#else
#include "UnixSocket.hpp"
#endif
#include "Select.hpp"
#include "MsgHandler.hpp"
#include "EntityContainer.hpp"
#include "Action.hpp"

enum eColor : int {
  BLUE = 0,
  PINK = 20,
  GREEN = 40,
  RED = 60,
  DARK_BLUE = 80
};

class Game {
  public:
    Game(Socket &s);
    ~Game();

    void connection();
    void play();
    void spawnThread();
  private:
    std::shared_ptr<World> _world;
    std::shared_ptr<Select> _select;
    std::shared_ptr<MsgHandler> _msgHandler;
    std::shared_ptr<EntityContainer> _entityContainer;
    std::shared_ptr<Action> _action;
    std::shared_ptr<std::thread> _t;
    bool _isConnected = false;
    bool _isCurrentGame = false;
    Socket &_socket;
};