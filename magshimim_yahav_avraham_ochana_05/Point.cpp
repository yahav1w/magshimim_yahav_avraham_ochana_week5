#include "Point.h"
#include <cmath>

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

Point::~Point()
{
}

Point Point::operator+(const Point& other) const
{
	Point tmp = *(new Point(this->x,this->y));
	tmp.x += other.x;
	tmp.y += other.y;
	return tmp;
}

Point& Point::operator+=(const Point& other)
{
	*this = this->operator+(other);
	return *this;
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

double Point::distance(const Point& other) const
{
	return sqrt(pow(this->x-other.x,2)+pow(this->y-other.y,2));
}
