//
// Created by thomas on 20-12-18.
//

#ifndef LINAL_SPACESHIP_MODELFACTORY_H
#define LINAL_SPACESHIP_MODELFACTORY_H

#include <memory>
#include "Updatable.h"
#include "Camera.h"

Updatable *createSpaceship(Camera const& camera);
Updatable *createShootingTarget(Camera const& camera);
Updatable *createBullet(Camera const& camera);

#endif //LINAL_SPACESHIP_MODELFACTORY_H
