#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "Fixed.hpp"

class Vector 
{
    public:
        Vector(); // constructor
        Vector(Fixed& x, Fixed& y); // Fixed constructor
        Vector(const Vector& other); //copy constructor
        Vector&  operator=(Vector& other); // copy assignment operator
        ~Vector(); // destructor 

        // Methods: 

    private:
        // Member variables & utils functions:
        Fixed   _X;
        Fixed   _Y;
};

#endif // Vector_HPP
