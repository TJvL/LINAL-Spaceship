//
// Created by thomas on 20-12-18.
//

#ifndef LINAL_SPACESHIP_MODELFACTORY_H
#define LINAL_SPACESHIP_MODELFACTORY_H

#include <memory>
#include "Updatable.h"
#include "../math/Mesh.h"
#include "Camera.h"

class Game;

Updatable *createSpaceship(Game *game);
Updatable *createShootingTarget(Game *game);
Updatable *createBullet(Game *game, Vector3 origin, Vector3 side, Vector3 top, Vector3 heading);
Camera *createCamera();

#endif //LINAL_SPACESHIP_MODELFACTORY_H
