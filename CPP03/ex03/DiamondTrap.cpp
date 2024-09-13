#include "DiamondTrap.hpp"

// Custom constructors & Destructors : 

//Constructor
DiamondTrap::DiamondTrap(const std::string& name)
 : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _Name(name)
{
    std::cout << "Custom DiamondTrap Constructor called for " << _Name << "\n";
    this->_HitPoints = FragTrap::_HitPoints;
    this->_EnergyPoints = ScavTrap::_EnergyPoints;
    this->_AttackDamage = FragTrap::_AttackDamage;
    
}

//Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _Name(other._Name)
{
    std::cout << "Custom DiamondTrap copy Constructor called" << "\n";
    this->_HitPoints = other._HitPoints;
    this->_EnergyPoints = other._EnergyPoints;
    this->_AttackDamage = other._AttackDamage;
}

// Copy Assignment Operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) 
{
    std::cout << "Custom DiamondTrap copy assignment operator called\n";

    if (this == &other)
        return (*this);
    this->_Name = other._Name;
    this->_HitPoints = other._HitPoints;
    this->_EnergyPoints = other._EnergyPoints;
    this->_AttackDamage = other._AttackDamage;

    return (*this);
}

//Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "Custom DiamondTrap Destructor called" <<"\n";
}

// Methods:

std::string	DiamondTrap::getName() const
{
	return (this->_Name);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->_Name << "\n";
    std::cout << "DiamondTrap's Claptrap name: " << ClapTrap::_Name << "\n";
}
