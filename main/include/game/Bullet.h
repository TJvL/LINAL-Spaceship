//
// Created by thomas on 19-12-18.
//

#ifndef LINAL_SPACESHIP_BULLET_H
#define LINAL_SPACESHIP_BULLET_H

#include "Updatable.h"
#include "WireModel.h"
#include "Game.h"

class Bullet : public Updatable {
 public:
  Bullet(WireModel wireModel, Game *game);

  sf::Drawable &update(const deltaTime &deltaTime, const std::map<sf::Keyboard::Key, bool> &keyboard) override;

 private:
  size_t timeAlive_;
  WireModel wireModel_;
  Game *game_;
};

#endif //LINAL_SPACESHIP_BULLET_H
