#include "core/RenderAgent.hpp"

RenderAgent::RenderAgent(sf::RenderWindow* window, SpriteManager* spriteManager, WorldManager* worldManager) {
  this->window = window;
  this->spriteManager = spriteManager;
  this->worldManager = worldManager;
}

void RenderAgent::render() {
  window->clear(sf::Color(20, 20, 20, 20));

  Chunk* chunk = worldManager->getMainChunk();
  
  for (int x = 0; x < CHUNK_WIDTH; x++) {
    for (int y = 0; y < CHUNK_HEIGHT; y++) {

      sf::Sprite sprite;
      std::string name;

      int id = chunk->blocks[x + y * CHUNK_WIDTH];
      switch(id) {
        case 1:
          name = "stone";
        break;
      }
      
      sprite = spriteManager->get(name);
      sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
      window->draw(sprite);
    }
  }

  window->display();
}
