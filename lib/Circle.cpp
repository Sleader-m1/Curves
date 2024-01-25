#include "Circle.h"
#include <cmath>

Circle::Circle(double radius):radius(radius){}

Point Circle::derivative(double t) const{
	/*Используем центральную разностную производную
		f(t)' = [ f(t + dt) - f(t - dt) ] / 2*dt
	 
	Point func_arg_PLUS_dT = getPoint(t + dT);  //f(t + dt)
	Point func_arg_MINUS_dT = getPoint(t - dT); //f(t - dt)

	return Point{ 
		(double)(func_arg_PLUS_dT.getX() - func_arg_MINUS_dT.getX()) / (2 * dT), // f'x
		(double)(func_arg_PLUS_dT.getY() - func_arg_MINUS_dT.getY()) / (2 * dT), // f'y
		0 			Должно быть: 
          			(func_arg_PLUS_dT.getZ() - func_arg_MINUS_dT.getZ()) / (2 * dT)
		  			но известно, что вдоль Oz движения нет => f'z = 0
	};
	*/
	return Point{radius * (-sin(t)), radius * cos(t), 0};
}

Point Circle::getPoint(double t) const {
	return Point{radius * cos(t), radius * sin(t), 0}; //	x = r * cos(t) |-------| y = r * sin(t) |-------| z = 0
}

bool operator<(const Circle& lhs, const Circle& rhs) {
	return lhs.radius < rhs.radius;
}

double Circle::getRadius() const{
	return radius;
}

Circle::~Circle(){}