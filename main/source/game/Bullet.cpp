//
// Created by thomas on 19-12-18.
//

#include "../../include/game/Bullet.h"

Bullet::Bullet(WireModel wireModel)
    : wireModel_(wireModel) {}

sf::Drawable &Bullet::update(const deltaTime &deltaTime, const std::map<sf::Keyboard::Key, bool> &keyboard) {
  return wireModel_;
}
