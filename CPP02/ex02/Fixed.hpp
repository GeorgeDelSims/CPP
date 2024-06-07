#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed 
{
    public:
    
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed& other);
        // assignment operator overload
        Fixed&      operator=(const Fixed& other);
        // comparison operators overload 
        bool        Fixed::operator>(const Fixed& other) const;
        bool        Fixed::operator>=(const Fixed& other) const;
        bool        Fixed::operator<(const Fixed& other) const;
        bool        Fixed::operator<=(const Fixed& other) const;
        bool        Fixed::operator==(const Fixed& other) const;
        bool        Fixed::operator!=(const Fixed& other) const;
        // arithmetic operators overload 
        Fixed       Fixed::operator+(const Fixed& other) const;
        Fixed       Fixed::operator-(const Fixed& other) const;
        Fixed       Fixed::operator*(const Fixed& other) const;
        Fixed       Fixed::operator/(const Fixed& other) const;
        // incrementation operator overload 
        Fixed&      Fixed::operator++();
        Fixed       Fixed::operator++(int);
        Fixed&      Fixed::operator--();
        Fixed       Fixed::operator--(int);

        ~Fixed();
        
        int     toInt(void) const;
        float   toFloat(void) const;

        friend std::ostream&   operator<<(std::ostream& outputStream, const Fixed& fixedPoint);
        // friend function can access private members from outside the class
    
    private:
        
        // member variables
        static const int    _fractionalBits = 8;
        int                 _fixedPointValue;
        // member functions

};

#endif
