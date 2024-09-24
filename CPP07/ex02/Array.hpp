#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>

template<typename T>
class Array 
{
    public:
        // constructor (default)
        Array() : _array(new T[0]), _arraySize(0) {};

        // constructor
        Array(unsigned int n) : _array(new T[n]), _arraySize(n) {};

        //copy constructor
        Array(const Array& other) : _array(new T[other._arraySize]), _arraySize(other._arraySize)
        {
            for (unsigned int i = 0; i < other._arraySize; ++i)
                this->_array[i] = other._array[i];
        }; 
        
        // copy assignment operator
        Array&  operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] _array;

                this = Array(other);
            }
            return (*this);
        }; 
        
        // destructor 
        ~Array()
        {
            delete [] _array;
        }; 

        // Methods: 

        unsigned int    size(void) const
        {
            return (this->_arraySize);
        };

        // Subscript operator
        T&          operator[](unsigned int index) 
        {
            if (index >= _arraySize) 
                throw std::out_of_range("Index out of bounds");
            return (_array[index]);
        }

        // Const version of subscript operator
        const T&    operator[](unsigned int index) const 
        {
            if (index >= _arraySize) 
            {
                throw std::out_of_range("Index out of bounds");
            }
            return (_array[index]);
        }
        
    private:
        // Private member variables & utils functions:
        T               *_array;
        unsigned int    _arraySize;
        
};

#endif // Array_HPP
