#include "core/TextureManager.hpp"

void TextureManager::add(const std::string& name, const std::string& filepath) {
  sf::Texture texture;
  texture.loadFromFile(filepath);

  textures[name] = texture;
}

TextureManager::TextureManager() {
  add("stone", "resources/stone.png");
  add("player", "resources/player.png");
}

sf::Texture& TextureManager::get(const std::string& name) {
  return textures[name];
}
