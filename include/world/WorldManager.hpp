#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#define CHUNK_WIDTH 4
#define CHUNK_HEIGHT 4
#define BLOCK_SIZE 32

#include <box2d/b2_world.h>
#include "world/Chunk.hpp"
#include "world/Player.hpp"
#include "core/TextureManager.hpp"

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

  Player* player;
  
  void initialize();

  void left();
  void right();

  ChunkNode* generate(int, ChunkNode*, ChunkNode*);

public:
  WorldManager(b2World*, InputHandler*, TextureManager*);
  ~WorldManager();

  void update(float);

  ChunkNode* get();
  Player* getPlayer();
};

#endif
