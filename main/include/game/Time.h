//
// Created by thomas on 19-12-18.
//

#ifndef LINAL_SPACESHIP_TIME_H
#define LINAL_SPACESHIP_TIME_H

#include <chrono>

using timer = std::chrono::steady_clock;
using timePoint = timer::time_point;
using deltaTime = timer::duration;

inline timePoint now() { return timer::now(); }

inline float toSeconds(deltaTime deltaTime) {
  return std::chrono::duration_cast<std::chrono::duration<float>>(deltaTime).count();
}

inline deltaTime fromSeconds(float sec) {
  return std::chrono::duration_cast<deltaTime>(
      std::chrono::duration<float>(sec));
}

#endif //LINAL_SPACESHIP_TIME_H
