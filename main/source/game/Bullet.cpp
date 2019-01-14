//
// Created by thomas on 19-12-18.
//

#include "../../include/game/Bullet.h"
#include "../../include/math/Transform.h"

Bullet::Bullet(WireModel wireModel, Game *game): wireModel_(wireModel), timeAlive_{300}, game_{game} {}

sf::Drawable &Bullet::update(const deltaTime &deltaTime, const std::map<sf::Keyboard::Key, bool> &keyboard) {

  Transform::translate(wireModel_.mesh_.origin, wireModel_.mesh_.side, wireModel_.mesh_.top, wireModel_.mesh_.heading, { 0., 0., 5. });

  if (--timeAlive_ == 0) {
	  game_->addToRemove(this);
  }
  return wireModel_;
}
