#include "core/GameManager.hpp"

GameManager::GameManager() {
  this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Hello World", sf::Style::Titlebar | sf::Style::Close);
  this->world = new b2World(b2Vec2(0.f, 0.f));

  BodyFactory* bodyFactory = new BodyFactory(this->world);
  this->factory = new GameObjectFactory(bodyFactory); 
}

GameManager::~GameManager() {
  delete this->world;
  delete this->window;
}

void GameManager::update() {
  world->Step(TIME_STEP, 6, 2);

  while (this->window->pollEvent(ev)) {
    switch(ev.key.code) {
      case sf::Keyboard::Key::Escape:
        this->window->close();
        break;
      default:
        // Do nothing
        break;
    }
  }
}

bool GameManager::running() {
  return this->window->isOpen();
}
