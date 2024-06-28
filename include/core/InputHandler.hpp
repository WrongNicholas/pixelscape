#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <box2d/b2_math.h>

class InputHandler {
private:
  bool KEY_LEFT = false, KEY_RIGHT = false, KEY_DOWN = false, KEY_UP = false;

  sf::RenderWindow* window;
  sf::Event event;
public:
  InputHandler(sf::RenderWindow*);

  void pollEvents();

  b2Vec2 getInputVector();
};

#endif
