#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include "SFML/Graphics.hpp"
#include "core/BodyFactory.hpp"
#include "gameobject/GameObject.hpp"

class GameObjectFactory {
private:
  BodyFactory* factory;
public:
  GameObjectFactory(BodyFactory*);
  GameObject* create(const b2Vec2&, b2BodyType, sf::Texture* texture = nullptr);
};

#endif
