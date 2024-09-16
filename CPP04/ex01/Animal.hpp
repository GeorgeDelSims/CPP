#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal 
{
    public:
        Animal(); // constructor
        Animal(const Animal& other); //copy constructor
        Animal&  operator=(const Animal& other); // copy assignment operator
        virtual ~Animal(); // destructor 

        // Methods: 
        virtual void            makeSound() const;
        virtual std::string     getType() const;

    protected:
        std::string    type;

    private:
        // Private Member variables & utils functions:
};

#endif // Animal_HPP
