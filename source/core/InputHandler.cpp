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
        case sf::Keyboard::A:
          KEY_LEFT = true;
          break;
        case sf::Keyboard::D:
          KEY_RIGHT = true;
          break;
        case sf::Keyboard::W:
          KEY_UP = true;
          break;
        case sf::Keyboard::S:
          KEY_DOWN = true;
          break;

        default:
          // Do nothing
          break;
      }

    } else if (event.type == sf::Event::KeyReleased) {

      switch(event.key.code) {
        case sf::Keyboard::A:
          KEY_LEFT = false;
          break;
        case sf::Keyboard::D:
          KEY_RIGHT = false;
          break;
        case sf::Keyboard::W:
          KEY_UP = false;
          break;
        case sf::Keyboard::S:
          KEY_DOWN = false;
          break;

        default:
          // Do nothing
          break;
      }
    }

  }  
}

b2Vec2 InputHandler::getInputVector() {
  b2Vec2 inputVector = b2Vec2(
    static_cast<float>(KEY_RIGHT) - static_cast<float>(KEY_LEFT),
    static_cast<float>(KEY_DOWN) - static_cast<float>(KEY_UP)
  );

  float magnitude = sqrt(pow(inputVector.x, 2) + pow(inputVector.y, 2));
  if (magnitude != 0)
    return b2Vec2(inputVector.x / magnitude, inputVector.y / magnitude);
  return inputVector;
}
