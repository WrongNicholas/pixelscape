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

  sf::View view;
   
  void render(Chunk* chunk);
public:
  RenderAgent(sf::RenderWindow* window, SpriteManager* spriteManager, WorldManager* worldManager);
  void render();

  sf::View& getView();
};

#endif
