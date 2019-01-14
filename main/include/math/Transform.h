//
// Created by thomas on 20-12-18.
//

#ifndef LINAL_SPACESHIP_TRANSFORM_H
#define LINAL_SPACESHIP_TRANSFORM_H

#include "Matrix.h"

class Transform {
public:
	static void scale(Vector3 &scaling, Vector3 size) {

	}

	static void translate(Vector3 &origin, Vector3 const &side, Vector3 const &top, Vector3 const &heading, Vector3 direction);
	static void rotate(Vector3 &side, Vector3 &top, Vector3 &heading, Vector3 size);

	static Matrix4 perpMatrix(double fov, double aspect, double nearP, double farP);
	static Matrix4 cameraMatrix(Vector3 const &origin, Vector3 const &side, Vector3 const &top, Vector3 const &heading);
	static Matrix4 scalingMatrix(Vector3 const &scale);
	static Matrix4 translationMatrix(Vector3 const& direction);
	static Matrix4 rotationMatrix(Vector3 const &rotation);
	static Matrix4 rotationMatrix(Vector3 const &side, Vector3 const &top, Vector3 const &heading);
};

#endif //LINAL_SPACESHIP_TRANSFORM_H
