//
// Created by thomas on 19-12-18.
//

#ifndef LINAL_SPACESHIP_SPACESHIP_H
#define LINAL_SPACESHIP_SPACESHIP_H

#include "Updatable.h"

class Spaceship : public Updatable {
 public:
  sf::Drawable *update(const std::map<sf::Keyboard::Key, bool> &keyboard) override;
};

#endif //LINAL_SPACESHIP_SPACESHIP_H
