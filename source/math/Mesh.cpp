//
// Created by thomas on 19-12-18.
//

#include "../../include/math/Mesh.h"

Mesh::Mesh(std::vector<Vector3> points, std::vector<std::pair<size_t, size_t>> edges)
: points_(points), edges_(edges) {}

size_t Mesh::numberOfPoints() const {
  return points_.size();
}

size_t Mesh::numberOfEdges() const {
  return edges_.size();
}

std::vector<Vector3> const& Mesh::getPoints() const {
	return points_;
}

std::vector<std::pair<size_t, size_t>> const& Mesh::getEdges() const {
	return edges_;
}