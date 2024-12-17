#include "Circle.h"
#include <iostream>


Circle::Circle(Point center, double radius, std::string type, std::string name):Shape(name,type)
{
	if (radius < 0)
	{
		std::cout << "radius negetive" << std::endl;
		exit(1);
	}
	_center = center;
	_radius = radius;
}

Circle::~Circle()
{
}

Point Circle::getCenter() const
{
	return _center;
}

double Circle::getRadius() const
{
	return _radius;
}

double Circle::getArea() const
{
	return PI*pow(_radius,2);
}

double Circle::getPerimeter() const
{
	return 2*PI*_radius;
}

void Circle::move(const Point other)
{
	_center += other;
}

void Circle::printDetails() const
{
	std::cout << "Circle: center:" << this->_center.getX() << "," << this->_center.getY() << std::endl;
	std::cout << "radius:" << this->_radius << std::endl;
}

void Circle::draw(const Canvas& canvas)
{
	canvas.draw_circle(getCenter(), getRadius());
}

void Circle::clearDraw(const Canvas& canvas)
{
	canvas.clear_circle(getCenter(), getRadius());
}


