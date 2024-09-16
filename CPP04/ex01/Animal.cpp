#include "Animal.hpp"

//Constructor
Animal::Animal() : type("Animal") 
{
    std::cout << "Animal constructor called\n";
} 

//Copy constructor
Animal::Animal(const Animal& other) 
{
    std::cout << "Animal copy constructor called\n";
    this->type = other.type;
}

//Copy assignment operator
Animal&  Animal::operator=(const Animal& other) 
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

//Destructor
Animal::~Animal() 
{
    std::cout << "Animal destructor called\n";
}

// Methods:
void    Animal::makeSound() const
{
    std::cout << "animal " << this->getType() << " makes a generic sound" << "\n";
}

std::string     Animal::getType()const
{
    return (this->type);
}

