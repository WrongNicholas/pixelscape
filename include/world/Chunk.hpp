#ifndef CHUNK_H
#define CHUNK_H

#include <vector>

struct Chunk {
  int position;
  std::vector<int> blocks;

  ~Chunk() {
    blocks.clear();
  }
};

#endif
