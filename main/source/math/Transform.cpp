//
// Created by thomas on 20-12-18.
//

#include "../../include/math/Matrix.h"
#include "../../include/math/Transform.h"


void Transform::translate(Vector3 &origin, Vector3 const &side, Vector3 const &top, Vector3 const &heading, Vector3 direction) {
	origin = fromVector4(translationMatrix(origin) * rotationMatrix(side, top, heading) * toVector4(direction));
}

void Transform::rotate(Vector3 &side, Vector3 &top, Vector3 &heading, Vector3 size) {
	auto r = rotationMatrix(size);

	side = fromVector4(r * toVector4(side));
	heading = fromVector4(r * toVector4(heading));
	top = fromVector4(r * toVector4(top));
};


Matrix4 Transform::scalingMatrix(Vector3 const &scale) {
	auto x = scale.data[0], y = scale.data[1], z = scale.data[2];
	return {
		x,  0., 0., 0.,
		0.,  y, 0., 0.,
		0., 0.,  z, 0.,
		0., 0., 0., 1.
	};
}

Matrix4 Transform::cameraMatrix(Vector3 const &origin, Vector3 const &side, Vector3 const &top, Vector3 const &heading) {
	auto direction = (heading).normalize();
	auto up = (top).normalize();
	auto right = (side).normalize();
	return Matrix4{
		right.data[0], right.data[1], right.data[2], -(right.dot(origin)),
		up.data[0], up.data[1], up.data[2], -(up.dot(origin)),
		direction.data[0], direction.data[1], direction.data[2], -(direction.dot(origin)),
		0., 0.,  0., 1.
	};
}

Matrix4 Transform::perpMatrix(double fov, double aspect, double nearP, double farP) {
	auto scale{ nearP * std::tan((std::acos(-1) / 180) * fov / 2) };

	auto a = 1 / scale;
	auto q = a / aspect;

	auto b = -farP / (farP - nearP);
	auto c = (-farP * nearP) / (farP - nearP);

	return Matrix4{
		scale, 0., 0., 0.,
		0., scale, 0., 0.,
		0., 0., b, -1.,
		0., 0., c, 0.
	};
}

Matrix4 Transform::translationMatrix(Vector3 const& direction) {
	double x = direction.data[0];
	double y = direction.data[1];
	double z = direction.data[2];

	return Matrix4{
		1., 0., 0., x,
		0., 1., 0., y,
		0., 0., 1., z,
		0., 0., 0., 1.
	};
}

Matrix4 Transform::rotationMatrix(Vector3 const &rotation) {
	double a = rotation.data[0] * std::acos(-1) / 180;
	double b = rotation.data[1] * std::acos(-1) / 180;
	double y = rotation.data[2] * std::acos(-1) / 180;

	double sina = sin(a), cosa = cos(a);
	double sinb = sin(b), cosb = cos(b);
	double siny = sin(y), cosy = cos(y);

	Matrix4
		rx{
			   1.,    0.,    0., 0.,
			   0.,  cosa, -sina, 0.,
			   0.,  sina,  cosa, 0.,
			   0.,    0.,    0., 1. },
			   ry{
					cosb,    0.,  sinb, 0.,
					  0.,    1.,    0., 0.,
				   -sinb,    0.,  cosb, 0.,
					  0.,    0.,    0., 1. },
					  rz{
						  cosy, -siny,    0., 0.,
						  siny,  cosy,    0., 0.,
							0.,    0.,    1., 0.,
							0.,    0.,    0., 1. };

	return (rz * ry * rx);
}

Matrix4 Transform::rotationMatrix(Vector3 const &side, Vector3 const &top, Vector3 const &heading) {
	Vector3 sn = side.normalize();
	Vector3 tn = top.normalize();
	Vector3 hn = heading.normalize();

	return Matrix4{
		sn.data[0], tn.data[0], hn.data[0], 0.,
		sn.data[1], tn.data[1], hn.data[1], 0.,
		sn.data[2], tn.data[2], hn.data[2], 0.,
		0., 0., 0., 1.
	};
}