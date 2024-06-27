#include "core/RenderAgent.hpp"

void RenderAgent::render(sf::RenderWindow* window) {
  window->clear(sf::Color(20, 20, 20, 20));

  window->display();
}
