//
// Created by thomas on 18-12-18.
//

#include <SFML/Window/Event.hpp>
#include <iostream>
#include "../include/game/LoopControl.h"
#include "../include/game/Time.h"
#include "../include/Application.h"

const unsigned int screenWidth = 800;
const unsigned int screenHeight = 600;

Application::Application()
    : window_(sf::RenderWindow{sf::VideoMode{screenWidth, screenHeight}, "Spaceship", sf::Style::Close}) {
  window_.setKeyRepeatEnabled(false);
  auto view = window_.getDefaultView();
  auto &size = view.getSize();
  view.setSize(size.x, -size.y);
  window_.setView(view);
}

void Application::run() {
  game_.runLoop(window_, [&](LoopControl &control, deltaTime &deltaTime) {
    sf::Event event;
    while (window_.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
        control.quit = true;
      }

      if (event.type == sf::Event::KeyPressed) {
        control.keyboard[event.key.code] = true;
      }

      if (event.type == sf::Event::KeyReleased) {
        control.keyboard[event.key.code] = false;
      }
    }
  });

  window_.close();
}

int main() {
  Application app;
  app.run();
}
