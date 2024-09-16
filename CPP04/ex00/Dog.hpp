#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
    public:
        Dog(); // constructor
        Dog(const Dog& other); //copy constructor
        Dog&  operator=(const Dog& other); // copy assignment operator
        ~Dog(); // destructor 

        // Methods: 
        void            makeSound() const;
        std::string     getType() const;

    protected:
        std::string    type;

    private:
        // Member variables & utils functions:
};

#endif // Dog_HPP
