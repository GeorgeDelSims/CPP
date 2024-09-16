#ifndef BRAIN_HPP
# define BRAIN_HPP

#define MAX_IDEAS 100
#define ANIMALS 5

#include <string>
#include <iostream>
#include "Animal.hpp"


class Brain 
{
    public:
        Brain(); // constructor
        Brain(const Brain& other); //copy constructor
        Brain&  operator=(const Brain& other); // copy assignment operator
        ~Brain(); // destructor 

        // Public member variables
        std::string     ideas[MAX_IDEAS];
        // Methods:

    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
};

#endif // Brain_HPP
