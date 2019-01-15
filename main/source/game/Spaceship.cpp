//
// Created by thomas on 19-12-18.
//

#include "../../include/game/Spaceship.h"
#include "../../include/math/Transform.h"
#include "../../include/game/GameObjectCreation.h"
#include "../../include/game/Game.h"

Spaceship::Spaceship(WireModel wireModel, Game *game)
    : wireModel_(wireModel),
      movingForwards_(false),
      movingBackwards_(false),
      pitchingUp_(false),
      pitchingDown_(false),
      turningLeft_(false),
      turningRight_(false),
      rollingLeft_(false),
      rollingRight_(false),
      fired_{false},
      game_{game} {}

sf::Drawable &Spaceship::update(const deltaTime &deltaTime, const std::map<sf::Keyboard::Key, bool> &keyboard) {
  for (auto const&[key, isPressed] : keyboard) {
    setMovement(key, isPressed);
  }

  float moveAmount;
  if (movingForwards_) {
    moveAmount = 1;

  } else if (movingBackwards_) {
    moveAmount = -1;
  } else {
    moveAmount = 0;
  }

  float x;
  if (pitchingUp_) {
	  x = 1.f;
  }
  else if (pitchingDown_) {
	  x = -1.f;
  }
  else {
	  x = 0.f;
  }

  float y;
  if (turningLeft_) {
	  y = 1.f;
  }
  else if (turningRight_) {
	  y = -1.f;
  }
  else {
	  y = 0.f;
  }

  float z;
  if (rollingLeft_) {
	  z = 1.f;
  }
  else if (rollingRight_) {
	  z = -1.f;
  }
  else {
	  z = 0.f;
  }

  if (fired_) {
	  fireBullet();
	  fired_ = false;
  }

  move(this->wireModel_.mesh_, moveAmount);
  rotate(this->wireModel_.mesh_, x, y, z);

  return wireModel_;
}

void Spaceship::fireBullet() {
	auto mesh = wireModel_.mesh_;
	Vector3 origin = mesh.origin, side = mesh.side, top = mesh.top, heading = mesh.heading, direction = {0.f, 0.f, 42.f + 5.f};
	Transform::translate(origin, side, top, heading, direction);
	game_->addToAdd(createBullet(game_, origin, side, top, heading));
}

void Spaceship::move(Mesh &mesh, float moveAmount) {
	Transform::translate(mesh.origin, mesh.side, mesh.top, mesh.heading, {0.f, 0.f, moveAmount});
}

void Spaceship::rotate(Mesh &mesh, float x, float y, float z) {
	Transform::rotate(mesh.side, mesh.top, mesh.heading, {x, y, z});
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
	case sf::Keyboard::Key::Space:
		if (isPressed) {
			fired_ = true;
		}
		break;
  }
}
