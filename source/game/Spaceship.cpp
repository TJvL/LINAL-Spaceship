//
// Created by thomas on 19-12-18.
//

#include "../../include/game/Spaceship.h"
#include "../../include/math/Transform.h"
#include <iostream>
Spaceship::Spaceship(WireModel wireModel)
    : wireModel_(wireModel) {}

sf::Drawable &Spaceship::update(const std::map<sf::Keyboard::Key, bool> &keyboard) {
  for (auto const&[key, isPressed] : keyboard) {
    switch (key) {
	case sf::Keyboard::Key::A: if (isPressed) {
		auto mat = Transform::translationMatrix({ -10.,0.,0. });
		auto nv = Vector4{ wireModel_.mesh_.origin.data[0], wireModel_.mesh_.origin.data[1], wireModel_.mesh_.origin.data[2] , 1. };

		nv = mat * nv;
		wireModel_.mesh_.origin.data[0] = nv.data[0];
		wireModel_.mesh_.origin.data[1] = nv.data[1];
		wireModel_.mesh_.origin.data[2] = nv.data[2];
	}
	break;
	case sf::Keyboard::Key::D:  if (isPressed) {
		auto mat = Transform::translationMatrix({ 10.,0.,0. });
		auto nv = Vector4{ wireModel_.mesh_.origin.data[0], wireModel_.mesh_.origin.data[1], wireModel_.mesh_.origin.data[2] , 1. };

		nv = mat * nv;
		wireModel_.mesh_.origin.data[0] = nv.data[0];
		wireModel_.mesh_.origin.data[1] = nv.data[1];
		wireModel_.mesh_.origin.data[2] = nv.data[2];
	}break;
	case sf::Keyboard::Key::W: break;
	case sf::Keyboard::Key::S: break;

	case sf::Keyboard::Key::J: if (isPressed) {
		auto mat = Transform::rotationMatrix({ -1.,0.,0. });

		auto newHeading = mat * Vector4{ wireModel_.mesh_.heading.data[0], wireModel_.mesh_.heading.data[1], wireModel_.mesh_.heading.data[2], 1. };
		auto newTop = mat * Vector4{ wireModel_.mesh_.top.data[0], wireModel_.mesh_.top.data[1], wireModel_.mesh_.top.data[2], 1. };
		auto newSide = mat * Vector4{ wireModel_.mesh_.side.data[0], wireModel_.mesh_.side.data[1], wireModel_.mesh_.side.data[2], 1. };

		wireModel_.mesh_.top.data[0] = newTop.data[0];
		wireModel_.mesh_.top.data[1] = newTop.data[1];
		wireModel_.mesh_.top.data[2] = newTop.data[2];
		wireModel_.mesh_.heading.data[0] = newHeading.data[0];
		wireModel_.mesh_.heading.data[1] = newHeading.data[1];
		wireModel_.mesh_.heading.data[2] = newHeading.data[2];
		wireModel_.mesh_.side.data[0] = newSide.data[0];
		wireModel_.mesh_.side.data[1] = newSide.data[1];
		wireModel_.mesh_.side.data[2] = newSide.data[2];
	}break;
	case sf::Keyboard::Key::K:  if (isPressed) {
		auto mat = Transform::rotationMatrix({ 0.,-1.,0. });

		auto newHeading = mat * Vector4{ wireModel_.mesh_.heading.data[0], wireModel_.mesh_.heading.data[1], wireModel_.mesh_.heading.data[2], 1. };
		auto newTop = mat * Vector4{ wireModel_.mesh_.top.data[0], wireModel_.mesh_.top.data[1], wireModel_.mesh_.top.data[2], 1. };
		auto newSide = mat * Vector4{ wireModel_.mesh_.side.data[0], wireModel_.mesh_.side.data[1], wireModel_.mesh_.side.data[2], 1. };

		wireModel_.mesh_.top.data[0] = newTop.data[0];
		wireModel_.mesh_.top.data[1] = newTop.data[1];
		wireModel_.mesh_.top.data[2] = newTop.data[2];
		wireModel_.mesh_.heading.data[0] = newHeading.data[0];
		wireModel_.mesh_.heading.data[1] = newHeading.data[1];
		wireModel_.mesh_.heading.data[2] = newHeading.data[2];
		wireModel_.mesh_.side.data[0] = newSide.data[0];
		wireModel_.mesh_.side.data[1] = newSide.data[1];
		wireModel_.mesh_.side.data[2] = newSide.data[2];
	}break;
	case sf::Keyboard::Key::L:  if (isPressed) {
		auto mat = Transform::rotationMatrix({ 0.,0.,-1. });

		auto newHeading = mat * Vector4{ wireModel_.mesh_.heading.data[0], wireModel_.mesh_.heading.data[1], wireModel_.mesh_.heading.data[2], 1. };
		auto newTop = mat * Vector4{ wireModel_.mesh_.top.data[0], wireModel_.mesh_.top.data[1], wireModel_.mesh_.top.data[2], 1. };
		auto newSide = mat * Vector4{ wireModel_.mesh_.side.data[0], wireModel_.mesh_.side.data[1], wireModel_.mesh_.side.data[2], 1. };

		wireModel_.mesh_.top.data[0] = newTop.data[0];
		wireModel_.mesh_.top.data[1] = newTop.data[1];
		wireModel_.mesh_.top.data[2] = newTop.data[2];
		wireModel_.mesh_.heading.data[0] = newHeading.data[0];
		wireModel_.mesh_.heading.data[1] = newHeading.data[1];
		wireModel_.mesh_.heading.data[2] = newHeading.data[2];
		wireModel_.mesh_.side.data[0] = newSide.data[0];
		wireModel_.mesh_.side.data[1] = newSide.data[1];
		wireModel_.mesh_.side.data[2] = newSide.data[2];
	}break;
      // TODO: Check what keys are pressed or released and update accordingly.
    }

  }
  
  if(keyboard.size() > 0)
  std::cout << keyboard.size() << std::endl;
  return wireModel_;
}
