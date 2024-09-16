#include "AAnimal.hpp"

//Constructor
AAnimal::AAnimal() : type("AAnimal") 
{
    std::cout << "AAnimal constructor called\n";
} 

//Copy constructor
AAnimal::AAnimal(const AAnimal& other) 
{
    std::cout << "AAnimal copy constructor called\n";
    this->type = other.type;
}

//Copy assignment operator
AAnimal&  AAnimal::operator=(const AAnimal& other) 
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

//Destructor
AAnimal::~AAnimal() 
{
    std::cout << "AAnimal destructor called\n";
}

// Methods:
void    AAnimal::makeSound() const
{
    std::cout << "animal " << this->getType() << " makes a generic sound" << "\n";
}

std::string     AAnimal::getType()const
{
    return (this->type);
}

