//
// Created by thomas on 19-12-18.
//

#ifndef LINAL_SPACESHIP_UPDATABLE_H
#define LINAL_SPACESHIP_UPDATABLE_H

#include <map>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../../include/game/Time.h"

class Updatable {
 public:
  virtual ~Updatable() = default;

  virtual sf::Drawable &update(const deltaTime &deltaTime, const std::map<sf::Keyboard::Key, bool> &keyboard) = 0;
 protected:
  Updatable() = default;
};

#endif //LINAL_SPACESHIP_UPDATABLE_H
