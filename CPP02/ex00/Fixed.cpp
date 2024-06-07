#include "Fixed.hpp"

// Fixed constructor
Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Fixed Constructor from int
Fixed::Fixed(int num) : _fixedPointValue(num)
{
    // Constructor implementation
    std::cout << "Fixed int constructor called" << std::endl;
    _fixedPointValue = num << _fractionalBits;
}

// Copy constructor
Fixed::Fixed(const Fixed&  other) : _fixedPointValue(other._fixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed&  Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return (*this);
}

// Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}


int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits called" << std::endl;
    return (_fixedPointValue);
}

void    Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits called" << std::endl;
    _fixedPointValue = raw;
}

/*
int     Fixed::toInt(void) const
{
    return (_fixedPointValue >> _fractionalBits);
}

float    Fixed::toFloat(void) const
{
    return ((static_cast<float>(_fixedPointValue)) / (1 << _fractionalBits));
}
*/
