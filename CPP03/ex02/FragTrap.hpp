#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(const std::string& name); // constructor
        FragTrap(const FragTrap& other); //copy constructor
        FragTrap&  operator=(FragTrap& other); // copy assignment operator
        
        ~FragTrap(); // destructor 

        // Methods: 
        void    highFivesGuys(void);

    private:
        // Member variables & utils functions:
};

#endif // FragTrap_HPP
