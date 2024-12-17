#pragma once

#include "Shape.h"
#include "Point.h"

#define PI 3.14

class Circle : public Shape
{
private:
	Point _center;
	double _radius;
public:

	// Constructor
	Circle(Point center, double radius, std::string type, std::string name);

	// Destructor
	virtual ~Circle();

	// Getters
	Point getCenter() const;
	double getRadius() const;


	// Methods
	void draw(const Canvas& canvas) override;
	void clearDraw(const Canvas& canvas) override;

	// add fields
	// override functions if need (virtual + pure virtual)
	virtual double getArea() const;
	virtual double getPerimeter() const;
	virtual void move(const Point other);
	virtual void printDetails() const;
};