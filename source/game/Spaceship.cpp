//
// Created by thomas on 19-12-18.
//

#include "../../include/game/Spaceship.h"
#include "../../include/math/Transform.h"

Spaceship::Spaceship(WireModel wireModel)
    : wireModel_(wireModel),
      movingForwards_(false),
      movingBackwards_(false),
      pitchingUp_(false),
      pitchingDown_(false),
      turningLeft_(false),
      turningRight_(false),
      rollingLeft_(false),
      rollingRight_(false) {}

sf::Drawable &Spaceship::update(const deltaTime &deltaTime, const std::map<sf::Keyboard::Key, bool> &keyboard) {
  for (auto const&[key, isPressed] : keyboard) {
    setMovement(key, isPressed);
  }

  float moveAmount;
  if (movingForwards_) {
    moveAmount = 10;
  } else if (movingBackwards_) {
    moveAmount = -10;
  } else {
    moveAmount = 0;
  }

  return wireModel_;
}

void Spaceship::setMovement(const sf::Keyboard::Key &key, const bool isPressed) {
  switch (key) {
    case sf::Keyboard::Key::LShift:
      if (isPressed) {
        movingForwards_ = true;
        movingBackwards_ = false;
      } else {
        movingForwards_ = false;
      }
      break;

    case sf::Keyboard::Key::LControl:
      if (isPressed) {
        movingBackwards_ = true;
        movingForwards_ = false;
      } else {
        movingBackwards_ = false;
      }
      break;

    case sf::Keyboard::Key::W:
      if (isPressed) {
        pitchingDown_ = true;
        pitchingUp_ = false;
      } else {
        pitchingDown_ = false;
      }
      break;

    case sf::Keyboard::Key::S:
      if (isPressed) {
        pitchingUp_ = true;
        pitchingDown_ = false;
      } else {
        pitchingUp_ = false;
      }
      break;

    case sf::Keyboard::Key::A:
      if (isPressed) {
        turningLeft_ = true;
        turningRight_ = false;
      } else {
        turningLeft_ = false;
      }
      break;

    case sf::Keyboard::Key::D:
      if (isPressed) {
        turningRight_ = true;
        turningLeft_ = false;
      } else {
        turningRight_ = false;
      }
      break;

    case sf::Keyboard::Key::Q:
      if (isPressed) {
        rollingRight_ = true;
        rollingLeft_ = false;
      } else {
        rollingRight_ = false;
      }
      break;

    case sf::Keyboard::Key::E:
      if (isPressed) {
        rollingLeft_ = true;
        rollingRight_ = false;
      } else {
        rollingLeft_ = false;
      }
      break;
  }
}
