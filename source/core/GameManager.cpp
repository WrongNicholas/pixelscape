#include "core/GameManager.hpp"
//#include <iostream>

GameManager::GameManager() {
  this->videoMode.width = 800;
  this->videoMode.height = 800;

  window = new sf::RenderWindow(videoMode, "Pixelscape", sf::Style::Titlebar | sf::Style::Close);
  
  spriteManager = new SpriteManager();

  spriteManager->add("stone", "resources/stone.png");

  world = new b2World(b2Vec2(0.f, 0.f));

  worldManager = new WorldManager(world);

  renderAgent = new RenderAgent(window, spriteManager, worldManager);;

  inputHandler = new InputHandler(window);
}

GameManager::~GameManager() {
  delete window;
  delete spriteManager;
  delete renderAgent;
  delete inputHandler;
  delete worldManager;
}

void GameManager::update(float dt) {
  inputHandler->pollEvents();

  world->Step(dt, 6, 2);
}

void GameManager::render() {
  renderAgent->render();
}

const bool GameManager::running() const {
  return window->isOpen();
}
