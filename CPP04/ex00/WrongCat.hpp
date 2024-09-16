#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
    public:
        WrongCat(); // constructor
        WrongCat(const WrongCat& other); //copy constructor
        WrongCat&  operator=(const WrongCat& other); // copy assignment operator
        ~WrongCat(); // destructor 

        // Methods: 
        void            makeSound() const;
        std::string     getType() const;

    protected:
        std::string    type;

    private:
        // Private member variables & utils functions:
};

#endif // WrongCat_HPP
