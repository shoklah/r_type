/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Sound.cpp
*/

#include "../include/Sound.hpp"

bool Sound::loadSound(eSound sound)
{
  if (!_buffer.loadFromFile("./Res/audio/" + _files[sound] + ".wav")) {
    std::cout << "Cannot load sound" << std::endl;
    return (false);
  }
  _sound.setBuffer(_buffer);
  return (true);
}

void Sound::playSound()
{
  _sound.play();
  _sound.setVolume(50);
}

void Sound::stopSound()
{
  _sound.stop();
}

void Sound::printDebug()
{
  std::cout << " " << _buffer.getDuration().asSeconds() << " seconds" << std::endl;
  std::cout << " " << _buffer.getSampleRate() << " samples/sec" << std::endl;
  std::cout << " " << _buffer.getChannelCount() << " channels" << std::endl;
}