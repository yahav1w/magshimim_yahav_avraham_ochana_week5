#pragma once
#include "Shape.h"

class Arrow : public Shape
{
private:
	Point _source;
	Point _destination;
public:

	// Constructor
	Arrow(Point a, Point b, std::string type, std::string name);

	// Destructor
	virtual ~Arrow();

	// Getters
	Point getSource() const;
	Point getDestination() const;


	// Methods
	void draw(const Canvas& canvas) override;
	void clearDraw(const Canvas& canvas) override;

	// override functions if need (virtual + pure virtual)
	virtual double getPerimeter() const;
	virtual void move(const Point other);
	virtual double getArea() const;
	virtual void printDetails() const;
};