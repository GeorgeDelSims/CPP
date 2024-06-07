#include "Fixed.hpp"

// Fixed constructor
Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}


// Fixed Constructor from int
Fixed::Fixed(const int num) : _fixedPointValue(num)
{
    // Constructor implementation
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = num << _fractionalBits;
    std::cout << _fixedPointValue << std::endl;
}


// Fixed constructor from float
Fixed::Fixed(const float num) : _fixedPointValue(static_cast<int>(roundf(num * (1 << _fractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
    std::cout << _fixedPointValue << std::endl;
}


// Copy constructor
Fixed::Fixed(const Fixed&  other) : _fixedPointValue(other._fixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
}


// Copy assignment operator
Fixed&  Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return (*this);
}


std::ostream&   operator<<(std::ostream& outputStream, const Fixed& fixedPoint)
{
    outputStream << fixedPoint.toFloat();
    return (outputStream);
}


// Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}


// transform the fixed point value to an int (shift 8 bits to the right)
int     Fixed::toInt(void) const
{
    return (_fixedPointValue >> _fractionalBits);
}


// transform the fixed point value to a float
// first typecast it, then divide by ( 1 << _fractionalBits)
float    Fixed::toFloat(void) const
{
    return ((static_cast<float>(_fixedPointValue)) / (1 << _fractionalBits));
}
