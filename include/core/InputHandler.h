#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class InputHandler {
private:
  sf::RenderWindow* window;
  sf::Event event;

public:
  InputHandler(sf::RenderWindow* window);

  void pollEvents();
};

#endif
