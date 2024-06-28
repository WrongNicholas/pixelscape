#ifndef RENDERAGENT_H
#define RENDERAGENT_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "core/SpriteManager.hpp"
#include "world/WorldManager.hpp"

class RenderAgent {
private:
  sf::RenderWindow* window;
  SpriteManager* spriteManager;
  WorldManager* worldManager;

  const sf::Sprite& generateBlockSprite(int, int, int) const;
public:
  RenderAgent(sf::RenderWindow* window, SpriteManager* spriteManager, WorldManager* worldManager);
  void render();
};

#endif
