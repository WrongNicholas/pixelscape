#ifndef PLAYER_H
#define PLAYER_H

#include <box2d/b2_body.h>
#include <SFML/Graphics/Sprite.hpp>
#include "core/InputHandler.hpp"

class Player {
private:
  b2Body* body;
  sf::Sprite sprite;
public:
  Player(b2World*, InputHandler*, sf::Texture&);

  void update(float);

  sf::Sprite& getSprite();
};

#endif
