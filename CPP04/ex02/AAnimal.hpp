#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal 
{
    public:
        AAnimal(); // constructor
        AAnimal(const AAnimal& other); //copy constructor
        AAnimal&  operator=(const AAnimal& other); // copy assignment operator
        virtual ~AAnimal(); // destructor 

        // Methods: 
        virtual void            makeSound() const = 0;
        virtual std::string     getType() const;

    protected:
        std::string    type;

    private:
        // Private Member variables & utils functions:
};

#endif // Animal_HPP
