//
// Created by thomas on 19-12-18.
//

#ifndef LINAL_SPACESHIP_SPACESHIP_H
#define LINAL_SPACESHIP_SPACESHIP_H

#include "Updatable.h"
#include "WireModel.h"

class Spaceship : public Updatable {
 public:
  Spaceship(WireModel wireModel);

  sf::Drawable &update(const std::map<sf::Keyboard::Key, bool> &keyboard) override;

 private:
  WireModel wireModel_;
};

#endif //LINAL_SPACESHIP_SPACESHIP_H
