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
        bool        operator>(const Fixed& other) const;
        bool        operator>=(const Fixed& other) const;
        bool        operator<(const Fixed& other) const;
        bool        operator<=(const Fixed& other) const;
        bool        operator==(const Fixed& other) const;
        bool        operator!=(const Fixed& other) const;
        // arithmetic operators overload 
        Fixed       operator+(const Fixed& other) const;
        Fixed       operator-(const Fixed& other) const;
        Fixed       operator*(const Fixed& other) const;
        Fixed       operator/(const Fixed& other) const;
        // incrementation operator overload 
        Fixed&      operator++();
        Fixed       operator++(int);
        Fixed&      operator--();
        Fixed       operator--(int);
        // min max functions
        static const Fixed&    min(const Fixed&  num1, const Fixed& num2);
        static Fixed&          min(Fixed&  num1, Fixed& num2);
        static const Fixed&    max(const Fixed&  num1, const Fixed& num2);
        static Fixed&          max(Fixed&  num1, Fixed& num2);

        ~Fixed();
        
        int     toInt(void) const;
        float   toFloat(void) const;

    private:
        
        // member variables
        static const int    _fractionalBits = 8;
        int                 _fixedPointValue;
        // member functions

};

std::ostream&   operator<<(std::ostream& outputStream, const Fixed& fixedPoint);

#endif
