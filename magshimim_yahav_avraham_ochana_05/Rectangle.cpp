#include "Rectangle.h"
#include <iostream>


myShapes::Rectangle::Rectangle(Point a, double length, double width, std::string type, std::string name):Polygon(type,name)
{
	this->_points.push_back(a);
	this->_points.push_back(Point(a.getX() + length, a.getY()));
	this->_points.push_back(a + Point(length, width));
	this->_points.push_back(Point(a.getX(), a.getY() + length));
}

myShapes::Rectangle::~Rectangle()
{
}

void myShapes::Rectangle::draw(const Canvas& canvas)
{
	canvas.draw_rectangle(_points[0], _points[2]);
}

void myShapes::Rectangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_rectangle(_points[0], _points[2]);
}

double myShapes::Rectangle::getArea() const
{
	return _points[0].distance(_points[1])* _points[0].distance(_points[3]);
}

void myShapes::Rectangle::printDetails() const
{
	std::cout << "Rectangle: side 1:" << this->_points[0].distance(_points[1]) << std::endl;
	std::cout << "side 2:" << this->_points[1].distance(_points[2]) << std::endl;
	std::cout << "side 3:" << this->_points[2].distance(_points[3]) << std::endl;
	std::cout << "side 4:" << this->_points[3].distance(_points[0]) << std::endl;
}


