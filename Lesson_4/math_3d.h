#ifndef MATH_3D_H
#define MATH_3D_H

struct Vector3f
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	Vector3f() {
	}

	Vector3f(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}

};
#endif