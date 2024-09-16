#include "WrongAnimal.hpp"

//Constructor
WrongAnimal::WrongAnimal() : type("wronganimal") 
{
    std::cout << "WrongAnimal constructor called\n";
} 

//Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) 
{
    std::cout << "WrongAnimal copy constructor called\n";
    this->type = other.type;
}

//Copy assignment operator
WrongAnimal&  WrongAnimal::operator=(const WrongAnimal& other) 
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

//Destructor
WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal destructor called\n";
}

// Methods:
void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal " << this->getType() << " makes a generic sound" << "\n";
}

std::string     WrongAnimal::getType() const
{
    return (this->type);
}

