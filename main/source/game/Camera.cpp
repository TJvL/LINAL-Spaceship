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
      movingRight_(false),
      pitchingUp_(false),
      pitchingDown_(false),
      turningLeft_(false),
      turningRight_(false) {}

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

  double moveVerticalAmount;
  if (movingForwards_) {
    moveVerticalAmount = 5.;
  } else if (movingBackwards_) {
    moveVerticalAmount = -5.;
  } else {
    moveVerticalAmount = 0;
  }

  double moveHorizontalAmount;
  if (movingLeft_) {
    moveHorizontalAmount = -5.;
  } else if (movingRight_) {
    moveHorizontalAmount = 5.;
  } else {
    moveHorizontalAmount = 0;
  }

  double x;
  if (pitchingUp_) {
    x = 1.;
  } else if (pitchingDown_) {
    x = -1.;
  } else {
    x = 0.;
  }

  double y;
  if (turningLeft_) {
    y = 1.;
  } else if (turningRight_) {
    y = -1.;
  } else {
    y = 0.;
  }

  double z = 0.;

  rotate(camera_, x, y, z);
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
      } else {
        movingForwards_ = false;
      }
      break;

    case sf::Keyboard::Key::Down:
      if (isPressed) {
        movingBackwards_ = true;
        movingForwards_ = false;
      } else {
        movingBackwards_ = false;
      }
      break;

    case sf::Keyboard::Key::Left:
      if (isPressed) {
        movingLeft_ = true;
        movingRight_ = false;
      } else {
        movingLeft_ = false;
      }
      break;

    case sf::Keyboard::Key::Right:
      if (isPressed) {
        movingRight_ = true;
        movingLeft_ = false;
      } else {
        movingRight_ = false;
      }
      break;

    case sf::Keyboard::Key::I:
      if (isPressed) {
        pitchingDown_ = true;
        pitchingUp_ = false;
      } else {
        pitchingDown_ = false;
      }
      break;

    case sf::Keyboard::Key::K:
      if (isPressed) {
        pitchingUp_ = true;
        pitchingDown_ = false;
      } else {
        pitchingUp_ = false;
      }
      break;

    case sf::Keyboard::Key::J:
      if (isPressed) {
        turningLeft_ = true;
        turningRight_ = false;
      } else {
        turningLeft_ = false;
      }
      break;

    case sf::Keyboard::Key::L:
      if (isPressed) {
        turningRight_ = true;
        turningLeft_ = false;
      } else {
        turningRight_ = false;
      }
      break;
  }
}

void Camera::rotate(Mesh &mesh, double x, double y, double z) {
  Transform::rotate(mesh.side, mesh.top, mesh.heading, {x, y, z});
}

void Camera::moveVertical(Mesh &mesh, double moveAmount) {
  Transform::translate(mesh.origin, mesh.side, mesh.top, mesh.heading, {0., moveAmount, 0.});
}

void Camera::moveHorizontal(Mesh &mesh, double moveAmount) {
  Transform::translate(mesh.origin, mesh.side, mesh.top, mesh.heading, {moveAmount, 0., 0.});
}

