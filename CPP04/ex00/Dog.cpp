#include "Dog.hpp"

//Constructor
Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog constructor called\n";
}

//Copy constructor
Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called\n";
    this->type = other.type;
}

//Copy assignment operator
Dog&  Dog::operator=(const Dog& other) 
{
    if (this != &other)
    {   
        Animal::operator=(other); 
        this->type = other.type;
    }
    return (*this);
}

//Destructor
Dog::~Dog() 
{
    std::cout << "Dog destructor called\n";
}

// Methods:
void    Dog::makeSound() const
{
    std::cout << this->getType() << " makes sound: woof" << "\n";
}

std::string     Dog::getType() const
{
    return (this->type);
}

