#include "ScavTrap.hpp"

// Custom constructors & Destructors : 

//Constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "Custom ScavTrap Constructor called" << std::endl;
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
}
//Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "Custom ScavTrap copy Constructor called" << std::endl;
}

//Copy assignment operator
ScavTrap&  ScavTrap::operator=(ScavTrap& other)
{
    (void)other;
    std::cout << "Custom ScavTrap copy assignment operator called" << std::endl;

    return (*this);
}

//Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "Custom ScavTrap Destructor called" <<std::endl;
}

// Methods:
void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
