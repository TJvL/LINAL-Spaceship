//
// Created by thomas on 14-1-19.
//

#include "../../include/math/Transform.h"
#include "../../include/game/Camera.h"

Camera::Camera(Mesh camera)
    : camera_(camera),
      drawable_(new NullDrawable),
      movingForwards_(false),
      movingBackwards_(false),
      movingLeft_(false),
      movingRight_(false) {}

Camera::~Camera() {
  delete drawable_;
}

const Mesh &Camera::getCamera() const {
  return camera_;
}

sf::Drawable &Camera::update(const deltaTime &deltaTime, const std::map<sf::Keyboard::Key, bool> &keyboard) {
  for (auto const&[key, isPressed] : keyboard) {
    setMovement(key, isPressed);
  }

  float moveVerticalAmount;
  if (movingForwards_) {
    moveVerticalAmount = 5;
  } else if (movingBackwards_) {
    moveVerticalAmount = -5;
  } else {
    moveVerticalAmount = 0;
  }

  float moveHorizontalAmount;
  if (movingLeft_) {
    moveHorizontalAmount = 5;
  } else if (movingRight_) {
    moveHorizontalAmount = -5;
  } else {
    moveHorizontalAmount = 0;
  }

  moveVertical(camera_, moveVerticalAmount);
  moveHorizontal(camera_, moveHorizontalAmount);

  return *drawable_;
}

void Camera::setMovement(const sf::Keyboard::Key &key, const bool isPressed) {
  switch (key) {
    case sf::Keyboard::Key::Up:
      if (isPressed) {
        movingForwards_ = true;
        movingBackwards_ = false;
        movingLeft_ = false;
        movingRight_ = false;
      } else {
        movingForwards_ = false;
      }
      break;

    case sf::Keyboard::Key::Down:
      if (isPressed) {
        movingBackwards_ = true;
        movingForwards_ = false;
        movingLeft_ = false;
        movingRight_ = false;
      } else {
        movingBackwards_ = false;
      }
      break;

    case sf::Keyboard::Key::Left:
      if (isPressed) {
        movingLeft_ = true;
        movingForwards_ = false;
        movingBackwards_ = false;
        movingRight_ = false;
      } else {
        movingLeft_ = false;
      }
      break;

    case sf::Keyboard::Key::Right:
      if (isPressed) {
        movingRight_ = true;
        movingForwards_ = false;
        movingLeft_ = false;
        movingBackwards_ = false;
      } else {
        movingRight_ = false;
      }
      break;
  }
}

void Camera::moveVertical(Mesh &mesh, float moveAmount) {
  Transform::translate(mesh.origin, mesh.side, mesh.top, mesh.heading, {0.f, 0.f, moveAmount});
}

void Camera::moveHorizontal(Mesh &mesh, float moveAmount) {
  Transform::translate(mesh.origin, mesh.side, mesh.top, mesh.heading, {0.f, moveAmount, 0.f});
}

