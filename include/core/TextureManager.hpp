#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <map>
#include <string>
#include <SFML/Graphics/Texture.hpp>

class TextureManager {
private:
  void add(const std::string&, const std::string&);

  std::map<std::string, sf::Texture> textures;
public:
  TextureManager();

  sf::Texture& get(const std::string&);
};

#endif
