//
// Created by thomas on 18-12-18.
//

#ifndef LINAL_SPACESHIP_GAME_H
#define LINAL_SPACESHIP_GAME_H

#include <functional>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "LoopControl.h"
#include "Time.h"
#include "WireModel.h"
#include "Spaceship.h"
#include "ShootingTarget.h"
#include "Bullet.h"
#include "Camera.h"

class Game {
 public:
  Game();
  ~Game();

  void runLoop(sf::RenderWindow &window, std::function<void(LoopControl&, deltaTime&)> function);
  void addToAdd(Updatable *add) {to_add_updatables_.push_back(add);};
  void addToRemove(Updatable *remove) {to_remove_updatables_.push_back(remove);};
  Mesh const *getCamera()  const {return &camera_->getCamera();}
 private:
  sf::RenderStates currentRenderState_;
  std::vector<Updatable*> updatables_;
  std::vector<Updatable*> to_add_updatables_;
  std::vector<Updatable*> to_remove_updatables_;
  Camera *camera_;
};

#endif //LINAL_SPACESHIP_GAME_H
