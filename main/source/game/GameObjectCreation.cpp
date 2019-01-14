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
#include "../../include/game/Game.h"

Updatable *createSpaceship(Game *game) {
		auto points = std::vector<Vector3>{
		{    0.,     0., -14.},
		{-9.899, -9.899, -14.},
		{ 9.899, -9.899, -14.},
		{-9.899,  9.899, -14.},
		{ 9.899,  9.899, -14.},
		{  -14.,     0.,   0.},
		{   14.,     0.,   0.},
		{    0.,   -14.,   0.},
		{    0.,    14.,   0.},
		{    0.,     0.,  42.},
		{   -7.,    -7.,   0.},
		{    7.,    -7.,   0.},
		{   -7.,     7.,   0.},
		{    7.,     7.,   0.}};

		std::vector<std::pair<size_t, size_t>> lines{
		{0,  1},
		{0,  2},
		{0,  3},
		{0,  4},
		{0,  5},
		{0,  6},
		{0,  7},
		{0,  8},
		{1, 10},
		{2, 11},
		{3, 12},
		{4, 13},
		{5,  7},
		{5,  8},
		{5,  9},
		{6,  7},
		{6,  8},
		{6,  9},
		{7,  9},
		{8,  9}};

  Mesh mesh{points, lines};
  mesh.origin = {0., 0., -70.};
  WireModel model{mesh, *game->getCamera()};

  return new Spaceship(model, game);
}

Updatable *createShootingTarget(Game *game) {
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
  mesh.origin = {30., 0., -100.};
  WireModel model{mesh, *game->getCamera()};

  return new ShootingTarget(model);
}

Updatable *createBullet(Game *game, Vector3 origin, Vector3 side, Vector3 top, Vector3 heading) {
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
  mesh.origin = origin;
  mesh.side = side;
  mesh.top = top;
  mesh.heading = heading;
  WireModel model{mesh, *game->getCamera()};

  return new Bullet(model, game);
}

Camera *createCamera() {
	Mesh camera{{}, {}};
	camera.side = {1., 0., 0.};
	camera.top = {0., 1., 0.};
	camera.heading = {0., 0., 1.};
	camera.origin = {0., 0., 0.};
	return new Camera(camera);
}
