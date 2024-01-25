#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Figure.h"

class Ellipse : public Figure{
	double first_radius,
		  second_radius;
public:
	Ellipse(double first_radius, double second_radius);
	
	Point derivative(double t) const override;
	Point getPoint(double t) const override;

	~Ellipse();
};

#endif