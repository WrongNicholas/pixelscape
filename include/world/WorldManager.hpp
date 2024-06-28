#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#define CHUNK_WIDTH 16
#define CHUNK_HEIGHT 16
#define BLOCK_SIZE 32

#include <box2d/b2_world.h>
#include "world/Chunk.hpp"

class WorldManager {
private:
  b2World* world;
  Chunk* main;
  
  void initialize();
  Chunk* generate(int position, Chunk* left, Chunk* right);
public:
  WorldManager(b2World* world);
  ~WorldManager();

  Chunk* getMainChunk();
};

#endif
