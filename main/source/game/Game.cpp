//
// Created by thomas on 18-12-18.
//

#include "../../include/game/GameObjectCreation.h"
#include "../../include/game/LoopControl.h"
#include "../../include/game/Time.h"
#include "../../include/game/Game.h"

Game::Game()
	: currentRenderState_(sf::RenderStates::Default), camera_(createCamera()) {
  updatables_.push_back(createSpaceship(this));
  //updatables_.push_back(createShootingTarget(this));
  updatables_.push_back(camera_);
}

Game::~Game() {
  for (auto *updatable : updatables_) {
    delete updatable;
  }
}

void Game::runLoop(sf::RenderWindow &window, std::function<void(LoopControl &, deltaTime &)> function) {
  bool running = true;
  timePoint previousTime = now();
  auto deltaTime = previousTime - previousTime;
  LoopControl control{};
  while (running) {
    timePoint currentTime = now();
    deltaTime += currentTime - previousTime;
    previousTime = currentTime;

    // Execute input capture function.
    function(control, deltaTime);


    if (control.quit) {
      running = false;
    } else if (toSeconds(deltaTime) > (1.f/60.f)) {
      window.clear();
	  for (auto &updatable : updatables_) {
		  window.draw(updatable->update(deltaTime, control.keyboard), currentRenderState_);
	  }
      window.display();
	  control.keyboard.clear();
	  deltaTime = fromSeconds(0.f);
    }

	updatables_.erase(std::remove_if(updatables_.begin(), updatables_.end(), [&](auto *u) {
		return std::find(to_remove_updatables_.begin(), to_remove_updatables_.end(), u) != to_remove_updatables_.end();
	}), updatables_.end());
	to_remove_updatables_.end();
	std::for_each(to_add_updatables_.begin(), to_add_updatables_.end(), [&](auto *u) {
		updatables_.push_back(u);
	});
	to_add_updatables_.clear();
  }
}
