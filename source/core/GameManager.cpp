#include "core/GameManager.h"

GameManager::GameManager() {
  videoMode.width = 600;
  videoMode.height = 600;
  window = new sf::RenderWindow(videoMode, "Pixelscape", sf::Style::Titlebar | sf::Style::Close);

  world = new b2World(b2Vec2(0.f, 0.f));
}

void GameManager::update(float dt) {
  world->Step(dt, 6, 2);
}

void GameManager::render() {
  window->clear();

  window->display();
}

const bool GameManager::running() const {
  return window->isOpen();
}
