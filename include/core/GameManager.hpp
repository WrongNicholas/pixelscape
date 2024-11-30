#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "core/GameObjectFactory.hpp"

const float TIME_STEP = 1.f / 60.f;

class GameManager {
private:
  b2World* world;
  sf::RenderWindow* window;
  sf::Event ev;

  GameObjectFactory* factory;

public:
  GameManager();
  ~GameManager();

  void update();
  bool running();
};

#endif
