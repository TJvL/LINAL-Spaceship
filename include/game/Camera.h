#ifndef LINAL_SPACESHIP_CAMERA_H
#define LINAL_SPACESHIP_CAMERA_H

#include "../math/Matrix.h"

struct Camera {
	Vector3 eye{ 0.,0.,0. };
	Vector3 lookAt{ 0., 0., 50. };
	Vector3 up{ 0.,1.,0. };
};

#endif //LINAL_SPACESHIP_CAMERA_H
