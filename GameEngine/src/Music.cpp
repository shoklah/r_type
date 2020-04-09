/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Music.cpp
*/

#include "../include/Music.hpp"

bool Music::loadSound(eMusic music)
{
  if (!_music.openFromFile("./Res/audio/" + _files[music] + ".wav")) {
    std::cout << "Cannot load music" << std::endl;
    return (false);
  }
  return (true);
}

void    Music::playSound()
{
  _music.play();
  _music.setVolume(100);
  _music.setLoop(true);
}

void Music::stopSound()
{
  _music.setLoop(false);
  _music.stop();
}

void Music::printDebug()
{
  std::cout << " " << _music.getDuration().asSeconds() << " seconds" << std::endl;
  std::cout << " " << _music.getSampleRate() << " samples/sec" << std::endl;
  std::cout << " " << _music.getChannelCount() << " channels" << std::endl;
}