//
// Created by thomas on 20-12-18.
//

#ifndef LINAL_SPACESHIP_MODELFACTORY_H
#define LINAL_SPACESHIP_MODELFACTORY_H

#include <memory>
#include "Updatable.h"

Updatable *createSpaceship();
Updatable *createShootingTarget();
Updatable *createBullet();

#endif //LINAL_SPACESHIP_MODELFACTORY_H
