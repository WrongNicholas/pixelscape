#include "core/PrefabFactory.hpp"

PrefabFactory::PrefabFactory(BodyFactory* factory) {
  this->factory = factory;
}

GameObject* PrefabFactory::create(const b2Vec2& position, b2BodyType type, sf::Texture& texture) {
  b2Body* body = factory->create(position, type);

  GameObject* gameObject = new GameObject(body);
  
  gameObject->set_texture(texture);

  return gameObject;
}
