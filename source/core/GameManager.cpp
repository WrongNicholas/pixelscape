#include "core/GameManager.hpp"
//#include <iostream>

GameManager::GameManager() {
  this->videoMode.width = 1000;
  this->videoMode.height = 1000;

  window = new sf::RenderWindow(videoMode, "Pixelscape", sf::Style::Titlebar | sf::Style::Close);
  
  textureManager = new TextureManager();

  world = new b2World(b2Vec2(0.f, 0.f));

  worldManager = new WorldManager(world);

  renderAgent = new RenderAgent(window, textureManager, worldManager);;

  inputHandler = new InputHandler(window);
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

  float speed = 10.f;
  
  if (inputHandler->left) {
    renderAgent->getView().move(-speed, 0);
  }

  if (inputHandler->right) {
    renderAgent->getView().move(speed, 0);
  }

  if (inputHandler->chunkLeft) {
    worldManager->move(-1);
  }
  else if (inputHandler->chunkRight) {
    worldManager->move(1);
  }

  world->Step(dt, 6, 2);
}

void GameManager::render() {
  renderAgent->render();
}

const bool GameManager::running() const {
  return window->isOpen();
}
