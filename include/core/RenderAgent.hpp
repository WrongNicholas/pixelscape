#ifndef RENDERAGENT_H
#define RENDERAGENT_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "core/TextureManager.hpp"
#include "world/WorldManager.hpp"

class RenderAgent {
private:
  sf::RenderWindow* window;
  TextureManager* textureManager;
  WorldManager* worldManager;

  sf::View view;
   
  void render(Chunk*);
public:
  RenderAgent(sf::RenderWindow*, TextureManager*, WorldManager*);
  void render();

  sf::View& getView();
};

#endif
