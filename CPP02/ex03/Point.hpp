#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point 
{
    public:
        Point(); // constructor
        Point(const float xf, const float yf); // float constructor
        Point(const Point& other); // copy constructor
        ~Point(); // destructor 

        // Methods: 
        const Fixed&  get_x(void) const;
        const Fixed&  get_y(void) const;

    private:
        // Member variables & utils functions:
        const Fixed    _x;
        const Fixed    _y;
};

#endif // Point_HPP
