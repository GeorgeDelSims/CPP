#include "Weapon.hpp"

// Constructor with Name
Weapon::Weapon(std::string  type) 
{
    this->_type = type;
}

// Copy Constructor 
Weapon::Weapon(const Weapon& other) : _type(other._type) {}

// Default Destructor
Weapon::~Weapon() {}

// Copy Assignment Operator
Weapon& Weapon::operator=(const Weapon& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

// Methods: 
std::string     Weapon::getType()
{
    return this->_type;
}

void    Weapon::setType(std::string     type)
{
    this->_type = type;
}