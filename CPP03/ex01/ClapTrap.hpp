#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap 
{
    public:
        ClapTrap(); // constructor
        ClapTrap(std::string name); // constructor
        ClapTrap(const ClapTrap& other); //copy constructor
        ClapTrap&  operator=(ClapTrap& other); // copy assignment operator
        ~ClapTrap(); // destructor 

        // Methods:
        std::string     getName(void);
        unsigned int    getValue(const std::string value);
        void            attack(const std::string& target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);

    private:
        // Member variables & utils functions:
        std::string     _Name;
        unsigned int    _HitPoints;
        unsigned int    _EnergyPoints;
        unsigned int    _AttackDamage;

};

#endif // ClapTrap_HPP
