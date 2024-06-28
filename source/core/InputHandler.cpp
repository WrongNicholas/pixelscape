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

        // Temporary
        case sf::Keyboard::Left:
          left = true;
          break;
        case sf::Keyboard::Right:
          right = true;
          break;

        case sf::Keyboard::A:
          chunkLeft = true;
          break;
        case sf::Keyboard::D:
          chunkRight = true;
          break;

        default:
          // Do nothing
          break;
      }

    } else if (event.type == sf::Event::KeyReleased) {

      switch(event.key.code) {
        case sf::Keyboard::Left:
          left = false;
          break;
        case sf::Keyboard::Right:
          right = false;
          break;

        case sf::Keyboard::A:
          chunkLeft = false;
          break;
        case sf::Keyboard::D:
          chunkRight = false;
          break;
        default:
          // Do nothing
          break;
      }
    }

  }  
}
