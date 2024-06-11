#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point 
{
    public:
        Point(); // constructor
        Point(const float xf, const float yf); // constructor
        Point(const Point& other); //copy constructor
        Point&  operator=(const Point& other); // copy assignment operator
        ~Point(); // destructor 

        // Methods: 


    private:
        // Member variables & utils functions:
        Fixed&    _x;
        Fixed&    _y;
};

#endif // Point_HPP
