//
// Created by thomas on 19-12-18.
//

#ifndef LINAL_SPACESHIP_MESH_H
#define LINAL_SPACESHIP_MESH_H

#include <vector>
#include "Matrix.h"

class Mesh {
 public:
  explicit Mesh(std::vector<Vector3> points, std::vector<std::pair<size_t, size_t>> edges);
  Vector3 origin{0., 0., 100.};

  Vector3 heading{1., 0., 0.};
  Vector3 side{ 0., 1., 0.};
  Vector3 top{ 0., 0., 1.};

  Vector3 scaling{1., 1., 1.};

  size_t numberOfPoints() const;
  size_t numberOfEdges() const;

  std::vector<Vector3> const& getPoints() const;
  std::vector<std::pair<size_t, size_t>> const& getEdges() const;
 private:
  std::vector<Vector3> points_;
  std::vector<std::pair<size_t, size_t>> edges_;
};

#endif //LINAL_SPACESHIP_MESH_H
