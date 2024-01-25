#include "Helix.h"
#include <cmath>

Helix::Helix(double radius, double step):radius(radius), step(step){}

Point Helix::derivative(double t) const {
	/*Используем центральную разностную производную
		f(t)' = [ f(t + dt) - f(t - dt) ] / 2*dt
	 
	Point func_arg_PLUS_dT = Get_3D_point(t + dT);  //f(t + dt)
	Point func_arg_MINUS_dT = Get_3D_point(t - dT); //f(t - dt)

	return Point{ 
		(func_arg_PLUS_dT.getX() - func_arg_MINUS_dT.getX()) / (2 * dT), // f'x
		(func_arg_PLUS_dT.getY() - func_arg_MINUS_dT.getY()) / (2 * dT), // f'y
        (func_arg_PLUS_dT.getZ() - func_arg_MINUS_dT.getZ()) / (2 * dT)  // f'z
	};
	*/
	return Point{radius * (-sin(t)), radius * cos(t), step / (PI/2)};
}

Point Helix::getPoint(double t) const {
	return Point{radius * cos(t), radius * sin(t), step * t / (PI/2)}; //	x = r * cos(t) |-------| y = r * sin(t) |-------| z = step * t
}

Helix::~Helix(){}