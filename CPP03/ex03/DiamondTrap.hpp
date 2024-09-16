#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
    public: 

        DiamondTrap(const std::string& name); // Constructor 
        DiamondTrap(const DiamondTrap& other); // Copy constructor 
        DiamondTrap&    operator=(const DiamondTrap& other); // Copy Assignment operator

        ~DiamondTrap(); // Destructor

        // Methods:
        std::string     getName() const;
        void            whoAmI();

    private:
        std::string     _Name;
};

#endif // DiamondTrap_HPP
