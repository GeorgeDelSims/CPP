#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    // ClapTrap    clapA = ClapTrap("clapA");
    // ClapTrap    clapB = ClapTrap("clapB");
    DiamondTrap    diamsA = DiamondTrap("diamsA");

    diamsA.whoAmI();
    diamsA.getName();
    diamsA.takeDamage();


    return (0);
}
