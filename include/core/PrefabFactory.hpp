#ifndef PREFABFACTORY_H
#define PREFABFACTORY_H

#include "SFML/Graphics.hpp"
#include "core/BodyFactory.hpp"
#include "gameobject/GameObject.hpp"

class PrefabFactory {
private:
  BodyFactory* factory;
public:
  PrefabFactory(BodyFactory*);
  GameObject* create(const b2Vec2&, b2BodyType, sf::Texture&);
};

#endif
