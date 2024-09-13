#include "ClapTrap.hpp"

/* --------------- CONSTRUCTORS ---------------*/

//Constructor
ClapTrap::ClapTrap() : _Name(NULL), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

// Constructor with name as parameter
ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) 
{
	std::cout << "Constructor with name as parameter called" << std::endl;
}

//Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : _Name(other._Name), _HitPoints(other._HitPoints), _EnergyPoints(10), _AttackDamage(0) 
{
	std::cout << "Copy constructor called" << std::endl;
}

//Copy assignment operator
ClapTrap&  ClapTrap::operator=(ClapTrap& other)
{
	(void)other;
	std::cout << "Copy assignment operator called" << std::endl;

	return(*this);
}

//Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

/* --------------- METHODS ---------------*/

std::string	ClapTrap::getName()
{
	return (this->_Name);
}

unsigned int    ClapTrap::getValue(const std::string value)
{
	if (value == "_AttackDamage")
		return (this->_AttackDamage);
	else if (value == "_HitPoints")
		return (this->_HitPoints);
	else if (value == "_EnergyPoints")
		return (this->_EnergyPoints);
	else
	{
		std::cout << "Wrong value given to getValue() function" << std::endl;
		return (0);
	}
}

void    ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getValue("_AttackDamage") << " amount of damage" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	this->_HitPoints -= amount;
	std::cout << "ClapTrap " << this->getName() << " takes " << amount << " amount of damage" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoints < 1)
		std::cout << "ClapTrap " << this->getName() << " has no energy points left" << std::endl;
	else
	{
		this->_EnergyPoints--;
		this->_HitPoints += amount;
		std::cout << "ClapTrap " << this->getName() << " repairs itself, getting " << amount << " amount of hit points back" << std::endl;
	}
}
