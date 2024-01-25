#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(double first_radius, double second_radius):first_radius(first_radius),second_radius(second_radius){}

Point Ellipse::derivative(double t) const {
	/*Используем центральную разностную производную
		f(t)' = [ f(t + dt) - f(t - dt) ] / 2*dt
	 
	Point func_arg_PLUS_dT = getPoint(t + dT);  //f(t + dt)
	Point func_arg_MINUS_dT = getPoint(t - dT); //f(t - dt)

	return Point{ 
		(func_arg_PLUS_dT.getX() - func_arg_MINUS_dT.getX()) / (2 * dT), // f'x
		(func_arg_PLUS_dT.getY() - func_arg_MINUS_dT.getY()) / (2 * dT), // f'y
		0 			Должно быть: 
          			(func_arg_PLUS_dT.getZ() - func_arg_MINUS_dT.getZ()) / (2 * dT)
		  			но известно, что вдоль Oz движения нет => f'z = 0
	};
	*/
	return Point{first_radius * (-sin(t)) , second_radius * cos(t), 0};
}

Point Ellipse::getPoint(double t) const {
	return Point{first_radius * cos(t), second_radius * sin(t), 0}; //	x = a * cos(t) |-------| y = b * sin(t) |-------| z = 0
}

Ellipse::~Ellipse(){}