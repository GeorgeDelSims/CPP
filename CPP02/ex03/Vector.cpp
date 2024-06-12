#include "Vector.hpp"

//Constructor
Vector::Vector() : _X(0), _Y(0) {}

// Constructor from two floatrs
Vector::Vector(float x, float y) : _X(x), _Y(y) {};

// Constructor from two points (Bx - Ax, By - Ay)
Vector::Vector(const Point& a, const Point& b) : _X(b.get_x() - a.get_x()), _Y(b.get_y() - a.get_y()) {};

//Copy constructor
Vector::Vector(const Vector& other) : _X(other.get_X()), _Y(other.get_Y()) {};

//Copy assignment operator
Vector&  Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		_X = other._X;
		_Y = other._Y;
	}
	return (*this);
}

//Destructor
Vector::~Vector() {}

// Methods:

// cross product of two vectors AB and AP 
// = (ABx * APy) - (ABy * APx)
Fixed	Vector::crossproduct(const Vector& AB, const Vector& AP)
{
	return ((AB.get_X() * AP.get_Y()) - (AB.get_Y() * AP.get_X()));
}

const Fixed&  Vector::get_X(void) const
{
	return (this->_X);
}

const Fixed&  Vector::get_Y(void) const
{
	return (this->_Y);
}
