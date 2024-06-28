#include "world/WorldManager.hpp"

void WorldManager::initialize() {
  main = generate(0, nullptr, nullptr);
}

Chunk* WorldManager::generate(int position, Chunk* left, Chunk* right) {
  Chunk* chunk = new Chunk();

  for (int i = 0; i < CHUNK_WIDTH * CHUNK_HEIGHT; i++) {
    chunk->blocks.push_back(1);
  }

  chunk->position = position;

  return chunk;
}

WorldManager::WorldManager(b2World* world) {
  this->world = world;

  initialize();
}

WorldManager::~WorldManager() {
  delete main;
}

Chunk* WorldManager::getMainChunk() {
  return main;
}
