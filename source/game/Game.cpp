//
// Created by thomas on 18-12-18.
//

#include "../../include/game/GameObjectCreation.h"
#include "../../include/game/LoopControl.h"
#include "../../include/game/Time.h"
#include "../../include/game/Game.h"

Game::Game()
    : currentRenderState_(sf::RenderStates::Default) {
  // TODO: Implement creation functions for game objects and uncomment following two lines.
//  updatables_.push_back(createSpaceship());
//  updatables_.push_back(createShootingTarget());
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

    std::vector<sf::Drawable*> drawables;
    if (control.quit) {
      running = false;
    } else {
      for (auto &updatable : updatables_) {
        drawables.push_back(updatable->update(control.keyboard));
      }
    }

    if (control.render) {
      window.clear(sf::Color::White);
      for (auto &drawable : drawables) {
        window.draw(*drawable, currentRenderState_);
      }
      window.display();
    }
  }
}
