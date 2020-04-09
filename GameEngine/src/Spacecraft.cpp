/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Spacecraft.cpp
*/

#include "../include/Spacecraft.hpp"

void Spacecraft::printDebug() const
{
  std::cout << "Spacecraft " << _name << " ID " << _id << " have " << _amo << " amo at position " << _entity.getPosition().x << "," << _entity.getPosition().y << "." << std::endl;
}

void Spacecraft::playSound(eSound sound)
{
  _soundFiles.push_back("laser");
  _soundFiles.push_back("big_laser");
  _sound = std::make_shared<Sound>(_soundFiles);
  _sound->loadSound(sound);
  _sound->playSound();
}