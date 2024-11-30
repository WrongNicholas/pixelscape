#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"

class GameObject {
private:
  b2Body* body;
  sf::Sprite sprite;
public:
  GameObject(b2Body*);

  const b2Body* getBody() const;

  void update();
  void set_texture(sf::Texture&);
  sf::Sprite& get_sprite();
};

#endif
