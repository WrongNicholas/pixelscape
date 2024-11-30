#include "gameobject/GameObject.hpp"

GameObject::GameObject(b2Body* body) {
  this->body = body;
}

const b2Body* GameObject::getBody() const {
  return this->body;
}

void update() {
  
}

void GameObject::set_texture(sf::Texture& texture) {
  this->sprite.setTexture(texture);
  this->sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
}
