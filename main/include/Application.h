//
// Created by thomas on 18-12-18.
//

#ifndef LINAL_SPACESHIP_APPLICATION_H
#define LINAL_SPACESHIP_APPLICATION_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "game/Game.h"

class Application {
 public:
  Application();
  Application(const Application &other) = delete;
  Application(Application &&other) = delete;

  void run();

  Application &operator=(const Application &other) = delete;
  Application &operator=(Application &&other) = delete;

 private:
  sf::RenderWindow window_;
  Game game_;
};

#endif //LINAL_SPACESHIP_APPLICATION_H
