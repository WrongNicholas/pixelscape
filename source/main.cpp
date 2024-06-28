#include <chrono>
#include "core/GameManager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

int main() {

  GameManager game;

  // Game Loop
  auto previousTime = std::chrono::high_resolution_clock::now();
  while (game.running()) {
    auto currentTime = std::chrono::high_resolution_clock::now();
    float dt = std::chrono::duration<float>(currentTime - previousTime).count();
    previousTime = currentTime;

    // Update
    game.update(dt);

    // Render
    game.render();
  }

  return 0;
}
