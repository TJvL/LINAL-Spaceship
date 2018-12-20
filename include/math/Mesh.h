//
// Created by thomas on 19-12-18.
//

#ifndef LINAL_SPACESHIP_MESH_H
#define LINAL_SPACESHIP_MESH_H

#include <vector>
#include "Vector3.h"
#include "Vector4.h"

class Mesh {
 public:
  size_t numberOfPoints() const;
  size_t numberOfLines() const;
 private:
  std::vector<Vector3> points_;
  std::vector<std::pair<size_t, size_t>> lines_;
};

#endif //LINAL_SPACESHIP_MESH_H
