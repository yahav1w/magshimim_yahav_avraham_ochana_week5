#pragma once

#include "Shape.h"
#include <vector>

class Polygon : public Shape
{
protected:
	std::vector<Point> _points;
public:

	// Constructor
	Polygon(std::string type, std::string name);

	// Destructor
	virtual ~Polygon();

	// Methods
	virtual double getPerimeter() const;
	virtual void move(const Point other);
	// Getters
	std::vector<Point> getPoints() const;

	// override functions if need (virtual + pure virtual)
};