#include "Shape.h"

Shape::Shape(std::string name, std::string type)
{
	this->_name = name;
	this->_type = type;
}

Shape::~Shape()
{
}

std::string Shape::getType() const
{
	return _type;
}

std::string Shape::getName() const
{
	return _name;
}

