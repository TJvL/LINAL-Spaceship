//
// Created by thomas on 19-12-18.
//

#include "../../include/game/ShootingTarget.h"
#include "../../include/math/Transform.h"

ShootingTarget::ShootingTarget(WireModel wireModel)
    : wireModel_(wireModel) {}

sf::Drawable &ShootingTarget::update(const deltaTime &deltaTime, const std::map<sf::Keyboard::Key, bool> &keyboard) {
	static enum {grow = 0, wait1 = 1, shrink = 2, wait2 = 3} state = grow;
	static size_t count = 10;

		if (state == grow) {
			wireModel_.mesh_.scaling += 0.01;
		} else if(state == shrink) {
			wireModel_.mesh_.scaling -= 0.01;
		} else {}


	if (--count == 0) {
		switch (state) {
		case grow: state = wait1;
			count = 20;break;
		case wait1: state = shrink;
			count = 10;break;
		case shrink: state = wait2;
			count = 20;break;
		case wait2: state = grow; 
		count = 10;break;
		}
	}

  
  
  return wireModel_;
}
