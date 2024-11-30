#include "core/BodyFactory.hpp"

BodyFactory::BodyFactory(b2World* world) {
  this->world = world;
}

b2Body* BodyFactory::create(const b2Vec2& position, b2BodyType type) {
  b2BodyDef bodyDef;

  bodyDef.type = type;
  bodyDef.position = position;
  bodyDef.angle = 0.f;
  bodyDef.fixedRotation = true;

  return world->CreateBody(&bodyDef);
}
