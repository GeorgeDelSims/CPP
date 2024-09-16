#include "Dog.hpp"
#include "Brain.hpp"

//Constructor
Dog::Dog() : AAnimal()
{
    std::cout << "Dog constructor called\n";
    this->type = "Dog";
    this->_Brain = new Brain();
}

//Copy constructor
Dog::Dog(const Dog& other) : AAnimal(other)
{
    std::cout << "Dog copy constructor called\n";
    this->type = other.type;
    this->_Brain = new Brain(*other._Brain);
}

//Copy assignment operator
Dog&  Dog::operator=(const Dog& other) 
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
Dog::~Dog() 
{
    delete (this->_Brain);
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

