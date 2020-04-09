/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** RoomException.hpp
*/

#pragma once
#include <iostream>
#include <exception>

class RoomException : public std::exception
{
  virtual const char *what() const throw() {
    return ("No ROOM found.");
  }
};