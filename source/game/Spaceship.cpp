//
// Created by thomas on 19-12-18.
//

#include "../../include/game/Spaceship.h"

Spaceship::Spaceship(WireModel wireModel)
    : wireModel_(wireModel) {}

sf::Drawable &Spaceship::update(const std::map<sf::Keyboard::Key, bool> &keyboard) {
  for (auto const&[key, isPressed] : keyboard) {
    switch (key) {
      // TODO: Check what keys are pressed or released and update accordingly.
    }
  }
  return wireModel_;
}
