//
// Created by thomas on 18-12-18.
//

#include "../../include/game/GameObjectCreation.h"
#include "../../include/game/LoopControl.h"
#include "../../include/game/Time.h"
#include "../../include/game/Game.h"

Game::Game()
	: currentRenderState_(sf::RenderStates::Default), camera_{} {
  updatables_.push_back(createSpaceship(camera_));
  //updatables_.push_back(createShootingTarget(camera_));
}

Game::~Game() {
  for (auto *updatable : updatables_) {
    delete updatable;
  }
}

void Game::runLoop(sf::RenderWindow &window, std::function<void(LoopControl &, deltaTime &)> function) {
  bool running = true;
  timePoint previousTime = now();
  while (running) {
    timePoint currentTime = now();
    deltaTime deltaTime = currentTime - previousTime;
    previousTime = currentTime;
    LoopControl control{};

    // Execute input capture function.
    function(control, deltaTime);

    if (control.quit) {
      running = false;
    } else {
      window.clear(sf::Color::White);
      for (auto &updatable : updatables_) {
        window.draw(updatable->update(control.keyboard), currentRenderState_);
      }
      window.display();
    }
  }
}
