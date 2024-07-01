#include <chrono>
#include <thread>
#include "core/GameManager.hpp"

int main() {

  GameManager game;

  // Game Loop
  const auto fps = 60;
  const auto frameDuration = std::chrono::milliseconds(1000 / fps);

  while (game.running()) {
    auto startTime = std::chrono::steady_clock::now();

    // Update
    game.update(1.f/fps);

    // Render
    game.render();

    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    if (elapsedTime < frameDuration) {
      std::this_thread::sleep_for(frameDuration - elapsedTime);
    }
  }

  return 0;
}
