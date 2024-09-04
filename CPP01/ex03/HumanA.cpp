#include "HumanA.hpp"

// Constructor
HumanA::HumanA(const std::string  name, Weapon& weapon) : _name(name), _weapon(weapon) {}

// Copy Constructor 
HumanA::HumanA(const HumanA& other) : _name(other._name), _weapon(other._weapon) {}

// Copy Assignment Operator
HumanA& HumanA::operator=(const HumanA& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        // No assignment for _weapon since it's a reference; we don't rebind references.
        // The reference _weapon will always refer to the initially bound Weapon object.
    }
    return (*this);
}

// Destructor
HumanA::~HumanA() {}

void    HumanA::setWeapon(Weapon& weapon)
{
    this->_weapon = weapon;
}

Weapon&  HumanA::getWeapon() const
{
    return (this->_weapon);
}

void    HumanA::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}