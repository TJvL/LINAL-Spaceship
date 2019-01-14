#include "../../include/math/Matrix.h"

Vector4 toVector4(Vector3 const &vector3) {
	return {vector3.data[0], vector3.data[1], vector3.data[2], 1.};
}

Vector3 fromVector4(Vector4 const &vector4) {
	return {vector4.data[0], vector4.data[1], vector4.data[2]};
}