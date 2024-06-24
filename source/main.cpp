#include <chrono>
#include "core/GameManager.h"

int main() {

  GameManager game;

  auto previousTime = std::chrono::high_resolution_clock::now();
  while (game.running()) {
    auto currentTime = std::chrono::high_resolution_clock::now();
    float dt = std::chrono::duration<float>(currentTime - previousTime).count();
    previousTime = currentTime;

    game.update(dt);
    game.render();
  } 

  return 0;
}
