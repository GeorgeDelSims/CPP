#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
    public:
        Cat(); // constructor
        Cat(const Cat& other); //copy constructor
        Cat&  operator=(const Cat& other); // copy assignment operator
        ~Cat(); // destructor 

        // Methods: 
        void            makeSound() const;
        std::string     getType() const;

    protected:
        std::string    type;

    private:
        // Member variables & utils functions:
};

#endif // Cat_HPP
