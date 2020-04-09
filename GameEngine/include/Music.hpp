/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Music.hpp
*/

#pragma once

#include "AAudio.hpp"

enum eMusic
{
    HOME,
    IN_GAME
};

class Music : public AAudio
{
  public:
    Music(std::vector<std::string> files) : AAudio(files) {}
    ~Music() {}
    bool loadSound(eMusic music);
    void playSound();
    void stopSound();
    void printDebug();
  private:
    sf::Music _music;
};