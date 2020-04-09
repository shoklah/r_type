/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** NetException
*/

#pragma once
#include <iostream>
#include <exception>

class NetException : public std::exception
{
  virtual const char *what() const throw() {
    return "[Network ERROR] : ";
  }
};