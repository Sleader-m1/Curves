#ifndef HELIX_H
#define HELIX_H

#include "Figure.h"

class Helix : public Figure{
	double radius,
		  step;
public:
	Helix(double radius, double step);
	Point derivative(double t) const override;
	Point getPoint(double t) const override;
	~Helix();
};

#endif