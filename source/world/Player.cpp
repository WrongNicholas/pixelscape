#include <box2d/b2_world.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include "world/Player.hpp"

Player::Player(b2World* world, InputHandler* inputHandler, sf::Texture& texture) {
  
  b2BodyDef bodyDef;
  bodyDef.type = b2_kinematicBody;
  bodyDef.angle = 0;
  bodyDef.fixedRotation = true;
  bodyDef.position.Set(400, 0);
  
  body = world->CreateBody(&bodyDef);
  
  b2PolygonShape shape;
  shape.SetAsBox(16.f, 16.f);
  
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &shape;
  fixtureDef.density = 1;
  
  body->CreateFixture(&fixtureDef);

  sprite = sf::Sprite(texture);
}

void Player::update(float dt) {
  sprite.setPosition(body->GetPosition().x, body->GetPosition().y);
}

sf::Sprite& Player::getSprite() {
  return sprite;
}
