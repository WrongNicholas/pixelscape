#ifndef CHUNK_H
#define CHUNK_H

#include <vector>
#include <box2d/b2_body.h>

struct Chunk {
  b2Body* body;

  int position;
  std::vector<int> blocks;

  ~Chunk() {
    blocks.clear();
  }
};

#endif
