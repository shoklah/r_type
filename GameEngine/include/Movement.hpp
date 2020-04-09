/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Movement.hpp
*/

#pragma once

#include <iostream>
#include "IMovement.hpp"

class Movement : public IMovement
{
  public:
    Movement();
    ~Movement();
    virtual bool moveUp() final;
    virtual bool moveDown() final;
    virtual bool moveRight() final;
    virtual bool moveLeft() final;
};