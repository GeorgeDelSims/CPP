#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "Point.hpp"

class Vector 
{
    public:
        Vector(); // constructor
        Vector(float x, float y); // Float constructor
        Vector(const Point& a, const Point& b); // Point constructor
        Vector(const Vector& other); //copy constructor
        Vector&  operator=(const Vector& other); // copy assignment operator
        ~Vector(); // destructor 

        // Methods: 

        static Fixed    crossproduct(const Vector& AB, const Vector& AP);
        const Fixed&    get_X(void) const;
        const Fixed&    get_Y(void) const;

    private:
        // Member variables & utils functions:
        Fixed   _X;
        Fixed   _Y;
};

#endif // Vector_HPP

