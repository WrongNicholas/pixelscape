#include "world/Player.hpp"
#include <box2d/b2_world.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_contact.h>

#include <iostream>
bool Player::isGrounded() {
  return false;
}

Player::Player(b2World* world, InputHandler* inputHandler, sf::Texture& texture) {  
  this->world = world;
  this->inputHandler = inputHandler;

  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.angle = 0;
  bodyDef.fixedRotation = true;
  bodyDef.position.Set(0, -200);
  bodyDef.gravityScale = 1.f;

  body = world->CreateBody(&bodyDef);
  
  b2PolygonShape shape;
  shape.SetAsBox(32.f / 2.f, 32.f / 2.f);
  
  b2FixtureDef fixtureDef;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.f;
  fixtureDef.shape = &shape;

  body->CreateFixture(&fixtureDef);  

  sprite = sf::Sprite(texture);
  sprite.setOrigin(16.f, 16.f);

  
}

void Player::update(float dt) {
  b2Vec2 inputVector = inputHandler->getInputVector();

  float speed = 500.f;

  body->SetLinearVelocity(b2Vec2(inputVector.x * speed, body->GetLinearVelocity().y));

  sprite.setPosition(body->GetPosition().x, body->GetPosition().y);
}



sf::Sprite& Player::getSprite() {
  return sprite;
}
