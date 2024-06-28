#include "core/RenderAgent.hpp"
#include <SFML/Graphics/Sprite.hpp>

void RenderAgent::render(Chunk* chunk) {
  for (int x = 0; x < CHUNK_WIDTH; x++) {
    for (int y = 0; y < CHUNK_HEIGHT; y++) {

      sf::Sprite sprite(textureManager->get("stone"));
      int blockX = x * BLOCK_SIZE + chunk->position * BLOCK_SIZE * CHUNK_WIDTH;
      int blockY = y * BLOCK_SIZE;
      sprite.setPosition(blockX, blockY);
      window->draw(sprite);
    }
  }
}

RenderAgent::RenderAgent(sf::RenderWindow* window, TextureManager* textureManager, WorldManager* worldManager) {
  this->window = window;
  this->textureManager = textureManager;
  this->worldManager = worldManager;

  this->window->setView(view);
}

void RenderAgent::render() {
  window->clear(sf::Color(20, 20, 20, 20));

  window->setView(view); 

  ChunkNode* node = worldManager->get();
  render(node->chunk);
  render(node->left->chunk);
  render(node->right->chunk);

  Player* player = worldManager->getPlayer();
  window->draw(player->getSprite());

  window->display();
}

sf::View& RenderAgent::getView() {
  return view;
}
