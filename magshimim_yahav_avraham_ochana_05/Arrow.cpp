#include "Arrow.h"
#include <iostream>

Arrow::Arrow(Point a, Point b, std::string type, std::string name):Shape(name,type)
{
	if (a.getX() == b.getX() && a.getY() == b.getY())
	{
		exit(1);
	}
	_source = a;
	_destination = b;
}

Arrow::~Arrow()
{
}

Point Arrow::getSource() const
{
	return _source;
}

Point Arrow::getDestination() const
{
	return _destination;
}

double Arrow::getArea() const
{
	return 0;
}

void Arrow::printDetails() const
{
	std::cout << "Arrow: source:" << this->_source.getX() << "," << this->_source.getY() <<
		"destenation:" << this->_destination.getX() << "," << this->_destination.getY() << std::endl;
}

double Arrow::getPerimeter() const
{
	return _source.distance(_destination);
}
void Arrow::move(const Point other)
{
	_source += other;
	_destination += other;
}
void Arrow::draw(const Canvas& canvas)
{
	canvas.draw_arrow(_source, _destination);
}
void Arrow::clearDraw(const Canvas& canvas)
{
	canvas.clear_arrow(_source, _destination);
}


