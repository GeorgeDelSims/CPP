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
        Fixed&  operator=(const Fixed& other);
        ~Fixed();
        
        int     toInt(void) const;
        float   toFloat(void) const;

        //  function can access private members from outside the class
    
    private:
        
        // member variables
        static const int    _fractionalBits = 8;
        int                 _fixedPointValue;
        // member functions

};

std::ostream&   operator<<(std::ostream& outputStream, const Fixed& fixedPoint);

#endif
