#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <iostream>
#include <map>
#include "SFML/Graphics.hpp"

class TextureHandler {
private:
  std::map<std::string, sf::Texture> map;
public:
  TextureHandler() {
    add_texture("tile","resources/simple_tile.png"); 
  }
  
  void add_texture(const std::string &name, const std::string &path) {
    sf::Texture texture;
    
    if (!texture.loadFromFile(path)) {
      std::cerr << "ERROR: COULD NOT CREATE TEXTURE FROM FILE '" << path << "'" << std::endl;
    }
    else {
      map[name] = std::move(texture);
    }
  }

  sf::Texture& get_texture(const std::string& name) {
    return map.at(name);
  }
};

#endif
