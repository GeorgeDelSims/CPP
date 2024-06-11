#include "Point.hpp"

//Constructor
Point::Point() : _x(0), _y(0) {}

Point::Point(const float xf, const float yf)
{
	this->_x = Fixed(xf);
	this->_y = Fixed(yf);	
}

//Copy constructor
Point::Point(const Point& other) _x(other._x), _y(other._y)
{
	// std::cout << "Copy constructor called" << std::endl;
}

//Copy assignment operator
Point&  Point::operator=(const Point& other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return (*this);
}

//Destructor
Point::~Point() {}

// Methods:
