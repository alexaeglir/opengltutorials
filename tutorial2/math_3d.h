/**
* @file math_3d.h 
* @brief opengl vector helper file
*/
#ifndef __MATH_3D_H_
#define __MATH_3D_H_
struct Vector3f{
	float x;
	float y;
	float z;
	Vector3f(){
	}
	Vector3f(float _x,float _y, float _z)
	{
		x=_x;
		y=_y;
		z=_z;
	}

};
#endif
