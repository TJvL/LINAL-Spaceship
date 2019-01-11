//
// Created by thomas on 19-12-18.
//

#include "../../include/game/ShootingTarget.h"

ShootingTarget::ShootingTarget(WireModel wireModel)
    : wireModel_(wireModel) {}

sf::Drawable &ShootingTarget::update(const deltaTime &deltaTime, const std::map<sf::Keyboard::Key, bool> &keyboard) {
  return wireModel_;
}
