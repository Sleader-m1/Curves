#ifndef FIGURE_H
#define FIGURE_H

#define dT 0.05 //Приращение функции при подсчете производной
#define PI 3.1415

#include "Point.h"

class Figure{
public:
	virtual Point derivative(double t) const = 0;
	virtual Point getPoint(double t) const = 0;
	~Figure(){}
};

#endif