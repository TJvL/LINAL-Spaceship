//
// Created by thomas on 19-12-18.
//

#include "../../include/math/Mesh.h"

size_t Mesh::numberOfPoints() const {
  return points_.size();
}

size_t Mesh::numberOfLines() const {
  return lines_.size();
}
