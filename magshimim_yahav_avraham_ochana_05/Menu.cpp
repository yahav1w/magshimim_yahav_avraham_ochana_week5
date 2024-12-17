#include "Menu.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Arrow.h"
#include "Rectangle.h"
#include <iostream>
#include <stdlib.h> 

Menu::Menu() 
{
	_shapes = std::vector<Shape*>();
	int choice = -1,count = 0;
	while (true)
	{
		choice = -1;
		std::cout << "Enter 0 to add a new shape.\n" <<
			"Enter 1 to modify or get information from a current shape.\n" <<
			"Enter 2 to delete all of the shapes.\n" <<
			"Enter 3 to exit." << std::endl;
		while (choice < 0 || choice > 3)
		{
			std::cin >> choice;
		}
		system("cls");
		switch (choice)
		{
		case 0:
			_shapes.push_back(Option0());
			_shapes[count]->draw(_canvas);
			count++;
			break;
			case 1:
				Option1();
				break;
			case 2:
				Option2();
				break;
		case 3:
			exit(1);
			break;
		}
		system("cls");
	}
}

Menu::~Menu()
{
}

Shape* Menu::Option0()
{
	int choice = -1,radius = 0;
	int x = 0,x1 = 0,x2 = 0;
	int y = 0, y1 = 0,y2 = 0;
	int length = 0, width = 0;
	std::string name = "";
	std::cout << "Enter 0 to add a circle.\n" <<
		"Enter 1 to add an arrow.\n" <<
		"Enter 2 to add a triangle.\n" <<
		"Enter 3 to add a rectangle." << std::endl;
	while (choice < 0 || choice > 3)
	{
		std::cin >> choice;
	}
	switch (choice)
	{
	case 0:
		std::cout << "Please enter X:\n";
		std::cin >> x;
		std::cout << "Please enter Y:\n";
		std::cin >> y;
		std::cout << "Please enter radius:\n";
		std::cin >> radius;
		std::cout << "Please enter the name of the shape:\n";
		std::cin >> name;
		return new Circle(Point(x, y), radius, "Circle", name);
	case 1:
		std::cout << "Enter the X of point number: 1\n";
		std::cin >> x;
		std::cout << "Enter the Y of point number: 1\n";
		std::cin >> y;
		std::cout << "Enter the X of point number: 2\n";
		std::cin >> x1;
		std::cout << "Enter the Y of point number: 2\n";
		std::cin >> y1;
		std::cout << "Please enter the name of the shape:\n";
		std::cin >> name;
		return new Arrow(Point(x, y), Point(x1, y1), "Arrow", name);
	case 2:
		std::cout << "Enter the X of point number: 1\n";
		std::cin >> x;
		std::cout << "Enter the Y of point number: 1\n";
		std::cin >> y;
		std::cout << "Enter the X of point number: 2\n";
		std::cin >> x1;
		std::cout << "Enter the Y of point number: 2\n";
		std::cin >> y1;
		std::cout << "Enter the X of point number: 3\n";
		std::cin >> x2;
		std::cout << "Enter the Y of point number: 3\n";
		std::cin >> y2;
		std::cout << "Please enter the name of the shape:\n";
		std::cin >> name;
		return new Triangle(Point(x, y), Point(x1, y1), Point(x2, y2), "Arrow", name);
	case 3:
		std::cout << "Enter the X of the to left corner:\n";
		std::cin >> x;
		std::cout << "Enter the Y of the to left corner:\n";
		std::cin >> y;
		std::cout << "Please enter the length of the shape:\n";
		std::cin >> length;
		std::cout << "Please enter the width of the shape:\n";
		std::cin >> width;
		std::cout << "Please enter the name of the shape:\n";
		std::cin >> name;
		return new myShapes::Rectangle(Point(x, y), length, width, "Rectangle", name);
	}
}

void Menu::Option1()
{
	int choice = -1, shape = -1, moveX = 0, moveY = 0;
	std::string countinue = " ";

	while (shape < 0 || shape > _shapes.size() - 1)
	{
		system("cls");
		for (int i = 0; i < _shapes.size();i++)
		{
			std::cout << "Enter " << i << " for " << _shapes[i]->getName() << "(" << _shapes[i]->getType() << ")\n";
		}
		std::cin >> shape;
	}
	while (choice < 0 || choice > 3)
	{
		std::cout << "Enter 0 to move the shape\n" << "Enter 1 to get its details.\n" << "Enter 2 to remove the shape.\n";
		std::cin >> choice;
	}
	switch (choice)
	{
	case 0:
		system("cls");
		std::cout << "Please enter the X moving scale: ";
		std::cin >> moveX;
		std::cout << "Please enter the Y moving scale: ";
		std::cin >> moveY;
		_shapes[shape]->clearDraw(_canvas);
		_shapes[shape]->move(Point(moveX, moveY));
		_shapes[shape]->draw(_canvas);
		break;
	case 1:
		std::cout << _shapes[shape]->getType() << "	" << _shapes[shape]->getName() << " " << _shapes[shape]->getPerimeter() << " " << _shapes[shape]->getArea();
		std::cout << "\nPress Enter to continue . . . ";
		std::cin.ignore(2);
		break;
	case 2:
		_shapes[shape]->clearDraw(_canvas);
		_shapes.erase(_shapes.begin() + shape);
		for (int i = _shapes.size()-1;i >= 0 ;i--)
		{
			_shapes[i]->draw(_canvas);
		}
		break;
	}
}

void Menu::Option2()
{
	for (int i = 0;i < _shapes.size();i++)
	{
		_shapes[i]->clearDraw(_canvas);
	}
	for (int i = 0;i < _shapes.size();i++)
	{
		_shapes.pop_back();
	}
}

