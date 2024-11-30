#ifndef BODYFACTORY_H
#define BODYFACTORY_H

#include "box2d/box2d.h"
class BodyFactory {
private:
  b2World* world;

public:
  BodyFactory(b2World* world);
  b2Body* create(const b2Vec2& position, const b2BodyType type);
};

#endif
