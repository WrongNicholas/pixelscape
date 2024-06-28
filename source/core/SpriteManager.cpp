#include "core/SpriteManager.hpp"

#include <SFML/Graphics/Texture.hpp>

SpriteManager::~SpriteManager() {
  textures.clear();
  sprites.clear();
}

void SpriteManager::add(std::string name, std::string pathname) {
  sf::Texture texture;
  
  texture.loadFromFile(pathname);
  textures.push_back(texture);

  sf::Sprite sprite(textures.back());
  sprites.insert({name, sprite});
}

const sf::Sprite& SpriteManager::get(std::string name) const {
  return sprites.at(name);
}
