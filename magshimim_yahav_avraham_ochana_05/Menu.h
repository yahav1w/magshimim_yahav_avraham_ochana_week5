#pragma once
#include "Shape.h"
#include "Canvas.h"
#include <vector>

class Menu
{
public:

	Menu();
	~Menu();

	

private: 
	Canvas _canvas;

	Shape* Option0();
	void Option1();
	void Option2();
	// define a vector that contains the shapes
	std::vector<Shape*> _shapes;
};

