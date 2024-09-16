#include "WrongCat.hpp"

//Constructor
WrongCat::WrongCat() : WrongAnimal() 
{
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called\n";
}

//Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called\n";
    this->type = other.type;
}

//Copy assignment operator
WrongCat&  WrongCat::operator=(const WrongCat& other) 
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
        this->type = other.type;
    }
    return (*this);
}

//Destructor
WrongCat::~WrongCat() 
{
    std::cout << "WrongCat destructor called\n";
}

// Methods:
void    WrongCat::makeSound() const
{
    std::cout << this->getType() << " makes sound: WrongMeow" << "\n";
}

std::string     WrongCat::getType() const
{
    return (this->type);
}
