#include "core/InputHandler.hpp"

InputHandler::InputHandler(sf::RenderWindow* window) {
  this->window = window;
}

void InputHandler::pollEvents() {
  while (window->pollEvent(event)) {

    if (event.type == sf::Event::KeyPressed) {

      switch(event.key.code) {
        case sf::Keyboard::Escape:
          window->close();
          break;
        default:
          // Do nothing
          break;
      }

    }

  }  
}
