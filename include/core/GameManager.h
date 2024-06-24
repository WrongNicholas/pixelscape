#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <box2d/box2d.h>

class GameManager {
private:
  // SFML
  sf::RenderWindow* window;
  sf::VideoMode videoMode;

  // Box2D
  b2World* world;
public:
  GameManager();
  void update(float dt);
  void render();

  const bool running() const;
};

#endif
