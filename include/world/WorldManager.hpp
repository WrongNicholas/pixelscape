#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#define CHUNK_WIDTH 4
#define CHUNK_HEIGHT 4
#define BLOCK_SIZE 32

#include <box2d/b2_world.h>
#include "world/Chunk.hpp"

struct ChunkNode {
  Chunk* chunk;
  ChunkNode* left;
  ChunkNode* right;

  ~ChunkNode() {
    if (chunk != nullptr) {
      delete chunk;
      chunk = nullptr;
    }
    
    if (left != nullptr) {
      delete left;
      left = nullptr;
    }
    if (left != nullptr) {
      delete right;
      right = nullptr;
    }
  }
};

class WorldManager {
private:
  b2World* world;
  ChunkNode* main;
  
  void initialize();

  void left();
  void right();

  ChunkNode* generate(int, ChunkNode*, ChunkNode*);

public:
  WorldManager(b2World*);
  ~WorldManager();

  ChunkNode* getNode();

  void move(int);
};

#endif
