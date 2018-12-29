//
// Created by thomas on 20-12-18.
//

#include <vector>
#include "../../include/math/Matrix.h"
#include "../../include/math/Mesh.h"
#include "../../include/game/WireModel.h"
#include "../../include/game/Spaceship.h"
#include "../../include/game/ShootingTarget.h"
#include "../../include/game/Bullet.h"
#include "../../include/game/GameObjectCreation.h"

Updatable *createSpaceship(Camera const& camera) {
  std::vector<Vector3> points{
      // Body.
      Vector3{5., 0., 5.},
      Vector3{5., 0., -5.},
      Vector3{-5., 0., -5.},
      Vector3{-5., 0., 5.},
      Vector3{5., 10., 5.},
      Vector3{5., 10., -5.},
      Vector3{-5., 10., -5.},
      Vector3{-5., 10., 5.},
      // Tail.
      Vector3{0., 5., 10.},
      // Nose.
      Vector3{0., 0., -15.},
      // Right wing.
      Vector3{10., 0., 0.},
      // Left wing.
      Vector3{-10., 0., 0.}
  };

  std::vector<std::pair<size_t, size_t>> lines{
      // Body.
      std::make_pair<size_t, size_t>(0, 1),
      std::make_pair<size_t, size_t>(1, 2),
      std::make_pair<size_t, size_t>(2, 3),
      std::make_pair<size_t, size_t>(3, 0),
      std::make_pair<size_t, size_t>(4, 5),
      std::make_pair<size_t, size_t>(5, 6),
      std::make_pair<size_t, size_t>(6, 7),
      std::make_pair<size_t, size_t>(7, 4),
      std::make_pair<size_t, size_t>(0, 4),
      std::make_pair<size_t, size_t>(1, 5),
      std::make_pair<size_t, size_t>(2, 6),
      std::make_pair<size_t, size_t>(3, 7),
      // Tail.
      std::make_pair<size_t, size_t>(2, 8),
      std::make_pair<size_t, size_t>(3, 8),
      std::make_pair<size_t, size_t>(5, 8),
      std::make_pair<size_t, size_t>(6, 8),
      // Nose.
      std::make_pair<size_t, size_t>(0, 9),
      std::make_pair<size_t, size_t>(3, 9),
      std::make_pair<size_t, size_t>(4, 9),
      std::make_pair<size_t, size_t>(7, 9),
      // Right wing.
      std::make_pair<size_t, size_t>(0, 10),
      std::make_pair<size_t, size_t>(1, 10),
      std::make_pair<size_t, size_t>(5, 10),
      std::make_pair<size_t, size_t>(6, 10),
      // Left Wing.
      std::make_pair<size_t, size_t>(3, 11),
      std::make_pair<size_t, size_t>(4, 11),
      std::make_pair<size_t, size_t>(7, 11),
      std::make_pair<size_t, size_t>(8, 11),
  };

  Mesh mesh{points, lines};
  WireModel model{mesh, camera};

  return new Spaceship(model);
}

Updatable *createShootingTarget(Camera const& camera) {
  std::vector<Vector3> points{
      // Front points.
      Vector3{10., 10., 0.},
      Vector3{7.5, 7.5, 0.},
      Vector3{10., 0., 0.},
      Vector3{7.5, -7.5f, 0.},
      Vector3{0., -10., 0.},
      Vector3{-7.5f, -7.5f, 0.},
      Vector3{-10., 0., 0.},
      Vector3{-7.5f, 7.5f, 0.},
      // Back points.
      Vector3{10., 10., 2.5},
      Vector3{7.5, 7.5, 2.5},
      Vector3{10., 0., 2.5},
      Vector3{7.5, -7.5f, 2.5},
      Vector3{0., -10., 2.5},
      Vector3{-7.5f, -7.5f, 2.5},
      Vector3{-10., 0., 2.5},
      Vector3{-7.5f, 7.5f, 2.5},
  };

  std::vector<std::pair<size_t, size_t>> lines{
      // Front edges.
      std::make_pair<size_t, size_t>(0, 1),
      std::make_pair<size_t, size_t>(1, 2),
      std::make_pair<size_t, size_t>(2, 3),
      std::make_pair<size_t, size_t>(3, 4),
      std::make_pair<size_t, size_t>(4, 5),
      std::make_pair<size_t, size_t>(5, 6),
      std::make_pair<size_t, size_t>(6, 7),
      std::make_pair<size_t, size_t>(7, 0),
      // Back edges.
      std::make_pair<size_t, size_t>(8, 9),
      std::make_pair<size_t, size_t>(9, 10),
      std::make_pair<size_t, size_t>(10, 11),
      std::make_pair<size_t, size_t>(11, 12),
      std::make_pair<size_t, size_t>(12, 13),
      std::make_pair<size_t, size_t>(13, 14),
      std::make_pair<size_t, size_t>(14, 15),
      std::make_pair<size_t, size_t>(15, 8),
      // Connecting edges.
      std::make_pair<size_t, size_t>(0, 8),
      std::make_pair<size_t, size_t>(1, 9),
      std::make_pair<size_t, size_t>(2, 10),
      std::make_pair<size_t, size_t>(3, 11),
      std::make_pair<size_t, size_t>(4, 12),
      std::make_pair<size_t, size_t>(5, 13),
      std::make_pair<size_t, size_t>(6, 14),
      std::make_pair<size_t, size_t>(7, 15)
  };

  Mesh mesh{points, lines};
  WireModel model{mesh, camera };

  return new ShootingTarget(model);
}

Updatable *createBullet(Camera const& camera) {
  std::vector<Vector3> points{
      Vector3{0., 5., 0.},
      Vector3{2., 0., 0.},
      Vector3{-2., 0., 0.},
      Vector3{0., 0., 2.},
      Vector3{0., 0., -2.},
      Vector3{0., -3., 0.}
  };

  std::vector<std::pair<size_t, size_t>> lines{
      std::make_pair<size_t, size_t>(0, 1),
      std::make_pair<size_t, size_t>(0, 2),
      std::make_pair<size_t, size_t>(0, 3),
      std::make_pair<size_t, size_t>(0, 4),
      std::make_pair<size_t, size_t>(1, 5),
      std::make_pair<size_t, size_t>(2, 5),
      std::make_pair<size_t, size_t>(3, 5),
      std::make_pair<size_t, size_t>(4, 5)
  };

  Mesh mesh{points, lines};
  WireModel model{mesh, camera };

  return new Bullet(model);
}
