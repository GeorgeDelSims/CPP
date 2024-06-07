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
        Fixed(const Fixed& other);
        Fixed&  operator=(const Fixed& other);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        ~Fixed();

    private:
        // member variables
        static const int    _fractionalBits = 8;
        int                 _fixedPointValue;
        // member functions
        // int     toInt(void) const;
        // float   toFloat(void) const;
};

#endif
