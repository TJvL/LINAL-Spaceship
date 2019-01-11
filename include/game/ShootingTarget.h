//
// Created by thomas on 19-12-18.
//

#ifndef LINAL_SPACESHIP_SHOOTINGTARGET_H
#define LINAL_SPACESHIP_SHOOTINGTARGET_H

#include "Updatable.h"
#include "WireModel.h"

class ShootingTarget : public Updatable {
 public:
  ShootingTarget(WireModel wireModel);

  sf::Drawable &update(const deltaTime &deltaTime, const std::map<sf::Keyboard::Key, bool> &keyboard) override;

 private:
  WireModel wireModel_;
};

#endif //LINAL_SPACESHIP_SHOOTINGTARGET_H
