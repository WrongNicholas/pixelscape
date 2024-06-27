#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "core/RenderAgent.hpp"
#include "core/InputHandler.hpp"

class GameManager {
private:
  // SFML
  sf::RenderWindow* window;
  sf::VideoMode videoMode;
  
  RenderAgent renderAgent;
  InputHandler* inputHandler;
  
  // Box2D
  b2World* world;

  void initialize();
public:
  GameManager();
  ~GameManager();
  void update(float dt);
  void render();

  const bool running() const;
};

#endif
