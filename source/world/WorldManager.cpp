#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include "world/WorldManager.hpp"

void WorldManager::initialize() {
  main = generate(0, nullptr, nullptr);
  main->left = generate(-1, nullptr, main);
  main->right = generate(1, main, nullptr);
}

void WorldManager::left() {
  main = main->left;
  main->left = generate(main->chunk->position - 1, nullptr, main);
}

void WorldManager::right() {
  main = main->right;
  main->right = generate(main->chunk->position + 1, main, nullptr);
}

ChunkNode* WorldManager::generate(int position, ChunkNode* left, ChunkNode* right) {
  Chunk* chunk = new Chunk();
  chunk->position = position;

  b2BodyDef bodyDef;
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(position * CHUNK_WIDTH, 0);
  bodyDef.angle = 0;

  chunk->body = world->CreateBody(&bodyDef);

  for (int i = 0; i < CHUNK_WIDTH * CHUNK_HEIGHT; i++) {
    chunk->blocks.push_back(1);
    
    b2PolygonShape shape;
    shape.SetAsBox(BLOCK_SIZE / 2.f, BLOCK_SIZE / 2.f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1;
    chunk->body->CreateFixture(&fixtureDef);
  }

  ChunkNode* chunkNode = new ChunkNode();
  chunkNode->chunk = chunk;
  chunkNode->left = left;
  chunkNode->right = right;

  return chunkNode;
}

WorldManager::WorldManager(b2World* world) {
  this->world = world;

  initialize();
}

WorldManager::~WorldManager() {
  delete main;
}

ChunkNode* WorldManager::getNode() {
  return main;
}

void WorldManager::move(int direction) {
  if (direction == 1) {
    right();
  }
  else if (direction == -1) {
    left();
  }
}
