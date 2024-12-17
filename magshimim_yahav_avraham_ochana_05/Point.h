#pragma once

class Point
{
private:
	double x;
	double y;
public:

	// Constructors
	Point(); // initialize values to 0
	Point(double x, double y);

	// Destructor
	~Point();
	
	// Operators
	Point operator+(const Point& other) const;
	Point& operator+=(const Point& other);

	// Getters
	double getX() const;
	double getY() const;

	// Methods
	double distance(const Point& other) const;
};