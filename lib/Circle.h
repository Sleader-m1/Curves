#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

class Circle : public Figure{
	double radius;
public:
	Circle(double radius);
	Point derivative(double t) const override;
	Point getPoint(double t) const override;
	friend bool operator<(const Circle& lhs, const Circle& rhs); //Перегрузка оператора для сортировки массива по размеру радиуса
	double getRadius() const;
	~Circle();
};

#endif