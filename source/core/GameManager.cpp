#include "core/GameManager.hpp"
//#include <iostream>

GameManager::GameManager() {
  this->videoMode.width = 1000;
  this->videoMode.height = 1000;

  window = new sf::RenderWindow(videoMode, "Pixelscape", sf::Style::Titlebar | sf::Style::Close);

  inputHandler = new InputHandler(window);

  textureManager = new TextureManager();

  world = new b2World(b2Vec2(0.f, 0.f));

  worldManager = new WorldManager(world, inputHandler, textureManager);

  renderAgent = new RenderAgent(window, textureManager, worldManager);
}

GameManager::~GameManager() {
  delete window;
  
  delete textureManager;
  delete renderAgent;
  delete inputHandler;
  delete worldManager;

  delete world;
}

void GameManager::update(float dt) {
  inputHandler->pollEvents();

  worldManager->update(dt);

  world->Step(dt, 6, 2);
}

void GameManager::render() {
  renderAgent->render();
}

const bool GameManager::running() const {
  return window->isOpen();
}
