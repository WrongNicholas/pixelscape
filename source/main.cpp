#include "core/GameManager.hpp"
#include <chrono>
#include <thread>

int main() {

  GameManager game;

  sf::Clock clock;
  float accumulator = 0.f;

  auto frame_duration = std::chrono::duration<float>(TIME_STEP);
  auto start_time = std::chrono::steady_clock::now();

  while(game.running()) {
    float delta = clock.restart().asSeconds();
    accumulator += delta;

    while (accumulator >= TIME_STEP) {
      game.update();
      accumulator -= TIME_STEP;
    }

    auto elapsed = std::chrono::steady_clock::now() - start_time;
    auto sleep_time = frame_duration  - elapsed;
    if (sleep_time > std::chrono::milliseconds(0)) {
      std::this_thread::sleep_for(sleep_time);
    }

    start_time = std::chrono::steady_clock::now();
  }
  

  return 0;
}
