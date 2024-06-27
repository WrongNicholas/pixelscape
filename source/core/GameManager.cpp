#include "core/GameManager.hpp"
//#include <iostream>

GameManager::GameManager() {
  this->videoMode.width = 800;
  this->videoMode.height = 800;

  window = new sf::RenderWindow(videoMode, "Pixelscape", sf::Style::Titlebar | sf::Style::Close);
 
  inputHandler = new InputHandler(window);

  world = new b2World(b2Vec2(0.f, 0.f));
}

GameManager::~GameManager() {
  delete window;
}

void GameManager::update(float dt) {
  inputHandler->pollEvents();

  world->Step(dt, 6, 2);
}

void GameManager::render() {
  renderAgent.render(window);
}

const bool GameManager::running() const {
  return window->isOpen();
}
