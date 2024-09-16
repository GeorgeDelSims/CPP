#include "Cat.hpp"
#include "Brain.hpp"

//Constructor
Cat::Cat() : AAnimal() 
{
    std::cout << "Cat constructor called\n";
    this->type = "Cat";
    this->_Brain = new (Brain);
}

//Copy constructor
Cat::Cat(const Cat& other) : AAnimal(other)
{
    std::cout << "Cat copy constructor called\n";
    this->type = other.type;
    this->_Brain = new Brain(*other._Brain);
}

//Copy assignment operator
Cat&  Cat::operator=(const Cat& other) 
{
    if (this != &other)
    {
        AAnimal::operator=(other);
        this->type = other.type;
        delete (this->_Brain);
        this->_Brain = new Brain(*other._Brain);
    }
    return (*this);
}

//Destructor
Cat::~Cat() 
{
    delete (this->_Brain);
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
