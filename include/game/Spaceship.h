//
// Created by thomas on 19-12-18.
//

#ifndef LINAL_SPACESHIP_SPACESHIP_H
#define LINAL_SPACESHIP_SPACESHIP_H

#include "Updatable.h"
#include "WireModel.h"
#include "../math/mesh.h"

class Game;

class Spaceship : public Updatable {
 public:
  Spaceship(WireModel wireModel, Game *game);

  sf::Drawable &update(const deltaTime &deltaTime, const std::map<sf::Keyboard::Key, bool> &keyboard) override;

 private:
  void setMovement(const sf::Keyboard::Key &key, const bool isPressed);
  void move(Mesh &mesh, float moveAmount);
  void rotate(Mesh &mesh, float x, float y, float z);
  void fireBullet();
  bool movingForwards_;
  bool movingBackwards_;
  bool pitchingUp_;
  bool pitchingDown_;
  bool turningLeft_;
  bool turningRight_;
  bool rollingLeft_;
  bool rollingRight_;
  bool fired_;
  WireModel wireModel_;
  Game *game_;
};

#endif //LINAL_SPACESHIP_SPACESHIP_H
