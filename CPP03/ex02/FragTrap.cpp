#include "FragTrap.hpp"

//Constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) 
{
    std::cout << "Custom FragTrap Constructor called" << "\n";
    this->_HitPoints = 100;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;;
}

//Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) 
{
    std::cout << "Custom FragTrap copy Constructor called" << "\n";
}

//Copy assignment operator
FragTrap&  FragTrap::operator=(FragTrap& other)
{
    (void)other;
    std::cout << "Custom FragTrap copy assignment operator called" << "\n";
    
    return (*this);
}

//Destructor
FragTrap::~FragTrap() 
{
    std::cout << "Custom FragTrap Destructor called" << "\n";
}

// Methods:
void    FragTrap::highFivesGuys(void)
{
    std::cout << "Heyup lads, give us a high five then!" << "\n";
}
