#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
    public:
        // using ClapTrap::ClapTrap;
        ScavTrap(const std::string& name); // Constructor 
        ScavTrap(const ScavTrap& other); // Copy Constructor
        ScavTrap&  operator=(ScavTrap& other); // copy assignment operator
        
        ~ScavTrap(); // destructor 

        // Additional Methods that are not part of parent class ClapTrap
        void    guardGate();

    private:
        // Additional Member variables & utils functions (that are not part of the parent class):
};

#endif // ScavTrap_HPP
