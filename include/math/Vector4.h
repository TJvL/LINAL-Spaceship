//
// Created by thomas on 19-12-18.
//

#ifndef LINAL_SPACESHIP_VECTOR4_H
#define LINAL_SPACESHIP_VECTOR4_H

#include "Vector3.h"

class Vector4 : public Vector3 {
 public:
  Vector4();
  Vector4(float x, float y, float z, float w);

  float x;
  float y;
  float z;
  float w;
};

#endif //LINAL_SPACESHIP_VECTOR4_H
