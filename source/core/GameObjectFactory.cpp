#include "core/GameObjectFactory.hpp"

GameObjectFactory::GameObjectFactory(BodyFactory* factory) {
  this->factory = factory;
}

GameObject* GameObjectFactory::create(const b2Vec2& position, b2BodyType type, sf::Texture* texture) {
  b2Body* body = factory->create(position, type);

  GameObject* gameObject = new GameObject(body);

  if (texture) {
    gameObject->set_texture(*texture);
  }

  return gameObject;
}
