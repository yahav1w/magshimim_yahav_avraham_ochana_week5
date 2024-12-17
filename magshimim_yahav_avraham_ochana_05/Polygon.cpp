#include "Polygon.h"

Polygon::Polygon(std::string type, std::string name):Shape(name,type)
{
	_points = std::vector<Point>();
}

Polygon::~Polygon()
{
}


double Polygon::getPerimeter() const
{
	double sum = 0;
	for (int i = 0;i < _points.size() - 1;i++)
	{
		sum += _points[i].distance(_points[i + 1]);
	}
	sum += _points[_points.size() - 1].distance(_points[0]);
	return sum;
}

void Polygon::move(const Point other)
{
	for (int i = 0;i < 3;i++)
	{
		_points[i] += other;
	}
}

std::vector<Point> Polygon::getPoints() const
{
	return _points;
}

