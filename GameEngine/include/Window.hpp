/*
** EPITECH PROJECT, 2019
** Rtype
** File description:
** Window.hpp
*/

#pragma once

#include "IWindow.hpp"
#include "SpacecraftPlayer.hpp"
#include "SpacecraftEntities.hpp"
#include "Particles.hpp"
#include "Scroller.hpp"
#include "Music.hpp"
#include "Laser.hpp"

class Window : public IWindow
{
public:
  Window(int width, int height);
  ~Window(){};
  virtual void create() final;
  virtual bool isOpen() final;
  virtual void close(sf::Event event) final;
  virtual void clear(int red, int green, int blue) final;
  virtual void display() final;
  virtual void pollEvent(sf::Event event) final;
  void  playMusic(eMusic music);
  void createMusicVector();
  void drawSpacecraftPlayer(std::shared_ptr<SpacecraftPlayer> space);
  void drawSpacecraftEntity(std::shared_ptr<SpacecraftEntities> entity);
  void drawParticles(std::shared_ptr<ParticleSystem> particles);
  void drawScroll(std::shared_ptr<Scroller> _scroller);
  void printInfo();
private:
  int _width;
  int _height;
  const std::string _title;
  sf::RenderWindow _window;
  std::shared_ptr<Music> _music;
  std::vector<std::string> _musicFiles;
};