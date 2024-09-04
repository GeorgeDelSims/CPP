#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name) 
{
    this->_name = name;
    std::cout << this->_name << " created" << std::endl;
}

// Copy Constructor
Zombie::Zombie(const Zombie& other)
{
    this->_name = other._name;
}

// Destructor 
Zombie::~Zombie() 
{
    std::cout << this->_name << " destroyed" << std::endl;
}

// Copy Assignment Operator
Zombie& Zombie::operator=(const Zombie& other)
{
    if (this != &other)
    {
        this->_name = other._name;
    }
    return (*this);
}


// Add methods implementation here
void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
