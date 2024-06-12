#include "Point.hpp"

//Constructor
Point::Point() : _x(0), _y(0) {}

// Float constructor 
Point::Point(const float xf, const float yf) : _x(Fixed(xf)), _y(Fixed(yf)) {};

//Copy constructor
Point::Point(const Point& other) : _x(other._x), _y(other._y) {};

//Destructor
Point::~Point() {}

// Methods:

const Fixed&  Point::get_x(void) const
{
	return (this->_x);
}

const Fixed&  Point::get_y(void) const
{
	return (this->_y);
}
