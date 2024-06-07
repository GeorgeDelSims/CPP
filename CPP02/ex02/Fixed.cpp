#include "Fixed.hpp"

/* -------------- CONSTRUCTORS AND DESTRUCTOR --------------*/

// Fixed constructor
Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}


// Fixed Constructor from int
Fixed::Fixed(const int num) : _fixedPointValue(num)
{
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

// Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}


/* -------------- OPERATOR OVERLOAD FUNCTIONS --------------*/

// Copy assignment operator '='
Fixed&  Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return (*this);
}

/* --- Comparison operator overload functions --- */
bool  Fixed::operator>(const Fixed& other) const
{
    return (_fixedPointValue > other._fixedPointValue);
}

bool  Fixed::operator<(const Fixed& other) const
{
    return (_fixedPointValue < other._fixedPointValue);
}

bool  Fixed::operator>=(const Fixed& other) const
{
    return (_fixedPointValue >= other._fixedPointValue);
}

bool  Fixed::operator<=(const Fixed& other) const
{
    return (_fixedPointValue <= other._fixedPointValue);
}

bool  Fixed::operator==(const Fixed& other) const
{
    return (_fixedPointValue == other._fixedPointValue);
}

bool  Fixed::operator!=(const Fixed& other) const
{
    return (_fixedPointValue != other._fixedPointValue);
}

/* --- increment operator overload functions --- */

Fixed&  Fixed::operator++()
{
    _fixedPointValue++;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   temp = *this;

    _fixedPointValue++;
    return (temp);
}

Fixed&  Fixed::operator--()
{
    _fixedPointValue--;
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed   temp = *this;

    _fixedPointValue--;
    return (temp);
}


/* --- Arithmetic operator overload functions --- */

Fixed  Fixed::operator+(const Fixed& other) const
{
    Fixed   result;

    result._fixedPointValue = _fixedPointValue + other._fixedPointValue;
    return (result);
}

Fixed   Fixed::operator-(const Fixed& other) const
{
    Fixed   result;

    result._fixedPointValue = _fixedPointValue - other._fixedPointValue;
    return (result);
}

Fixed   Fixed::operator*(const Fixed& other) const
{
    Fixed   result;

    result._fixedPointValue = _fixedPointValue * other._fixedPointValue;
    return (result);
}

Fixed   Fixed::operator/(const Fixed& other) const
{
    Fixed   result;

    if (other._fixedPointValue == 0)
    {
        std::cout << "division by 0 impossible." << std::endl;
        return (result);
    }
    result._fixedPointValue = _fixedPointValue / other._fixedPointValue;
    return (result);
}

// Friend function for output stream operator overload
std::ostream&   operator<<(std::ostream& outputStream, const Fixed& fixedPoint)
{
    outputStream << fixedPoint.toFloat();
    return (outputStream);
}


/* -------------- PUBLIC MEMBER FUNCTIONS  --------------*/

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


&Fixed  Fixed::min(const Fixed&  num1, const Fixed& num2) const
{

}


&Fixed  Fixed::max(const Fixed&  num1, const Fixed& num2) const
{

}
