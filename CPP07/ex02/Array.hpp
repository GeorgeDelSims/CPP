#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>

template<typename T>
class Array 
{
    public:
        // constructor
        Array() : arr(nullptr), size_(0) {}; 
        Array(unsigned int n); // constructor
        Array(const Array& other); //copy constructor
        Array&  operator=(const Array& other); // copy assignment operator
        ~Array(); // destructor 

        // Methods: 

    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
        T   *arr;
        
};

#endif // Array_HPP
