#include "Cat.hpp"

//Constructor
Cat::Cat() : Animal() 
{
    this->type = "Cat";
    std::cout << "Cat constructor called\n";
}

//Copy constructor
Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called\n";
    this->type = other.type;
}

//Copy assignment operator
Cat&  Cat::operator=(const Cat& other) 
{
    if (this != &other)
    {
        Animal::operator=(other);
        this->type = other.type;
    }
    return (*this);
}

//Destructor
Cat::~Cat() 
{
    std::cout << "Cat destructor called\n";
}

// Methods:
void    Cat::makeSound() const
{
    std::cout << this->getType() << " makes sound: meow" << "\n";
}

std::string     Cat::getType() const
{
    return (this->type);
}
