#ifndef POINT_H
#define POINT_H
#include <ostream>
class Point{
	double x, y, z;
public:
	Point(double x = 0, double y = 0, double z = 0);

	//getters
	double getX();
	double getY();
	double getZ();

	//setters
	void setX(double x);
	void setY(double y);
	void setZ(double z);

	//output
	friend std::ostream& operator<<(std::ostream& out, const Point& p);

	~Point();
};

#endif