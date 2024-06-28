#ifndef PLAYER_H
#define PLAYER_H

#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include <SFML/Graphics/Sprite.hpp>
#include "core/InputHandler.hpp"

class Player {
private:
  b2World* world;
  b2Body* body; 

  InputHandler* inputHandler;
  sf::Sprite sprite;

  bool isGrounded();
public:
  Player(b2World*, InputHandler*, sf::Texture&);

  void update(float);

  sf::Sprite& getSprite();
};

#endif
