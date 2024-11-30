#include "gameobject/GameObject.hpp"
#include <iostream>

GameObject::GameObject(b2Body* body) {
  this->body = body;
  this->body->SetLinearVelocity(b2Vec2(1000, 1000));
}

const b2Body* GameObject::getBody() const {
  return this->body;
}

void GameObject::update() {
  b2Vec2 position = this->body->GetPosition();
  this->sprite.setPosition(position.x, position.y);
  std::cout << position.x << " " << position.y << std::endl;
}

void GameObject::set_texture(sf::Texture& texture) {
  this->sprite.setTexture(texture);
  this->sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
}

sf::Sprite& GameObject::get_sprite() {
  return sprite;
}
