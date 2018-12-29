//
// Created by thomas on 20-12-18.
//

#ifndef LINAL_SPACESHIP_TRANSFORM_H
#define LINAL_SPACESHIP_TRANSFORM_H

#include "Matrix.h"
#include "../game/Camera.h"

class Transform {
public:
	static Matrix4 translationMatrix(Vector3 const& direction) {
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

	static Matrix4 scalingMatrix(Vector3 const &scale) {
		auto x = scale.data[0], y = scale.data[1], z = scale.data[2];
		return {
			x,  0., 0., 0.,
			0.,  y, 0., 0.,
			0., 0.,  z, 0.,
			0., 0., 0., 1. };
	}

	static Matrix4 rotationMatrix(vector<3, double> rotation) {
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
			   0.,    0.,    0., 1.},
		ry{
			 cosb,    0.,  sinb, 0.,
			   0.,    1.,    0., 0.,
			-sinb,    0.,  cosb, 0.,
			   0.,    0.,    0., 1.},
		rz{
			 cosy, -siny,    0., 0.,
			 siny,  cosy,    0., 0.,
			   0.,    0.,    1., 0.,
			   0.,    0.,    0., 1.};

		return (rz * ry * rx);
	}

	static Matrix4 rotationMatrix(Vector3 const &heading, Vector3 const &side, Vector3 const &top) {
		Vector3 hn = heading.normalize();
		Vector3 sn = side.normalize();
		Vector3 tn = top.normalize();

		return Matrix4{
			hn.data[0], sn.data[0],tn.data[0], 0.,
			hn.data[1], sn.data[1],tn.data[1], 0.,
			hn.data[2], sn.data[2],tn.data[2], 0.,
			0., 0., 0., 1.
		};
	}

	static Matrix4 cameraMatrix(Camera const &camera) {
		auto z = (camera.eye - camera.lookAt).normalize();
		auto y = (camera.up).normalize();
		auto x = cross(y, z).normalize();
		y = cross(z, x).normalize();
		return Matrix4{
			x.data[0], x.data[1], x.data[2], -(x.dot(camera.eye)),
			y.data[0], y.data[1], y.data[2], -(y.dot(camera.eye)),
			z.data[0], z.data[1], z.data[2], -(z.dot(camera.eye)),
			0., 0.,  0., 1.
		};
	}

	static Matrix4 perpMatrix(double fov, double aspect, double near, double far) {
		auto scale{ near * std::tan((std::acos(-1) / 180) * fov / 2) };

		auto a = 1 / scale;
		auto q = a / aspect;

		auto b = -far / (far - near);
		auto c = (-far * near) / (far - near);

		return Matrix4{
			scale, 0., 0., 0.,
			0., scale, 0., 0.,
			0., 0., b, -1.,
			0., 0., c, 0.
		};
	}
};

#endif //LINAL_SPACESHIP_TRANSFORM_H
