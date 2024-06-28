#include "core/RenderAgent.hpp"

void RenderAgent::render(Chunk* chunk) {
  for (int x = 0; x < CHUNK_WIDTH; x++) {
    for (int y = 0; y < CHUNK_HEIGHT; y++) {

      sf::Sprite sprite(spriteManager->get("stone"));
      int blockX = x * BLOCK_SIZE + chunk->position * BLOCK_SIZE * CHUNK_WIDTH;
      int blockY = y * BLOCK_SIZE;
      sprite.setPosition(blockX, blockY);
      window->draw(sprite);
    }
  }
}

RenderAgent::RenderAgent(sf::RenderWindow* window, SpriteManager* spriteManager, WorldManager* worldManager) {
  this->window = window;
  this->spriteManager = spriteManager;
  this->worldManager = worldManager;

  this->window->setView(view);
}

void RenderAgent::render() {
  window->clear(sf::Color(20, 20, 20, 20));

  window->setView(view); 

  ChunkNode* node = worldManager->getNode();
  render(node->chunk);
  render(node->left->chunk);
  render(node->right->chunk);

  window->display();
}

sf::View& RenderAgent::getView() {
  return view;
}
