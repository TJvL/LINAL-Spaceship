//
// Created by thomas on 18-12-18.
//

#ifndef LINAL_SPACESHIP_TICKCONTROL_H
#define LINAL_SPACESHIP_TICKCONTROL_H

#include <map>
#include <SFML/Window/Event.hpp>

struct LoopControl {
  bool quit{false};
  bool render{true};
  std::map<sf::Keyboard::Key, bool> keyboard{};
};

#endif //LINAL_SPACESHIP_TICKCONTROL_H
