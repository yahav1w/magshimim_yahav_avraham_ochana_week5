#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(Point a, Point b, Point c, std::string type, std::string name) :Polygon(type, name)
{
	if (a.getX() == b.getX() && a.getX() == c.getX()
		|| a.getY() == b.getY() && a.getY() == c.getY()
		|| a.distance(b) + a.distance(c) < b.distance(c)
		|| b.distance(a) + b.distance(c) < a.distance(c)
		|| c.distance(a) + c.distance(b) < b.distance(a))
	{
		std::cout << "cant be a triangle" << std::endl;
		exit(1);
	}
	_points.push_back(a);
	_points.push_back(b);
	_points.push_back(c);
}

Triangle::~Triangle()
{
}

void Triangle::draw(const Canvas& canvas)
{
	canvas.draw_triangle(_points[0], _points[1], _points[2]);
}

void Triangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_triangle(_points[0], _points[1], _points[2]);
}

double Triangle::getArea() const
{
	double s = this->getPerimeter()/2;
	return sqrt(s * (s - _points[0].distance(_points[1])) 
		* (s - _points[1].distance(_points[2])) 
		* (s - _points[2].distance(_points[0])));
}

void Triangle::printDetails() const
{
	std::cout << "Triangle: side 1:" << this->_points[0].distance(_points[1]) << std::endl;
	std::cout << "side 2:" << this->_points[1].distance(_points[2]) << std::endl;
	std::cout << "side 3:" << this->_points[2].distance(_points[0]) << std::endl;
}
