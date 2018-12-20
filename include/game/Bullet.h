//
// Created by thomas on 19-12-18.
//

#ifndef LINAL_SPACESHIP_BULLET_H
#define LINAL_SPACESHIP_BULLET_H

#include "Updatable.h"

class Bullet : public Updatable {
 public:
  sf::Drawable *update(const std::map<sf::Keyboard::Key, bool> &keyboard) override;
};

#endif //LINAL_SPACESHIP_BULLET_H
