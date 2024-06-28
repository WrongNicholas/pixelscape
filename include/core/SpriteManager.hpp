#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <map>
#include <string>

class SpriteManager {
private:
  std::vector<sf::Texture> textures;
  std::map<std::string, sf::Sprite> sprites;
public:
  ~SpriteManager();
  void add(std::string name, std::string pathname);
  const sf::Sprite& get(std::string name) const;
};

#endif
