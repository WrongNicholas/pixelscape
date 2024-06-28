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
  bodyDef.position.Set(position * CHUNK_WIDTH * BLOCK_SIZE, 0);
  bodyDef.angle = 0;

  chunk->body = world->CreateBody(&bodyDef);

  for (int x = 0; x < CHUNK_WIDTH; x++) {
    for (int y = 0; y < CHUNK_HEIGHT; y++) {
      chunk->blocks.push_back(1);

      b2Vec2 points[] = {
        b2Vec2(x * BLOCK_SIZE, y * BLOCK_SIZE),
        b2Vec2(x * BLOCK_SIZE, (y + 1) * BLOCK_SIZE),
        b2Vec2((x + 1) * BLOCK_SIZE, (y + 1) * BLOCK_SIZE),
        b2Vec2((x + 1) * BLOCK_SIZE, y * BLOCK_SIZE)
      };

      b2PolygonShape shape;
      shape.Set(points, 4);

      b2FixtureDef fixtureDef;
      fixtureDef.shape = &shape; 
      chunk->body->CreateFixture(&fixtureDef);
    }
  }

  ChunkNode* chunkNode = new ChunkNode();
  chunkNode->chunk = chunk;
  chunkNode->left = left;
  chunkNode->right = right;

  return chunkNode;
}

WorldManager::WorldManager(b2World* world, InputHandler* inputHandler, TextureManager* textureManager) {
  this->world = world;

  initialize();

  player = new Player(world, inputHandler, textureManager->get("player"));
}

WorldManager::~WorldManager() {
  delete main;
  delete player;
}

void WorldManager::update(float dt) {
  player->update(dt);
}

ChunkNode* WorldManager::get() {
  return main;
}

Player* WorldManager::getPlayer() {
  return player;
}
