#include "ClapTrap.hpp"

int main()
{
    ClapTrap    clapA = ClapTrap("clapA");
    ClapTrap    clapB = ClapTrap("clapB");

    clapA.attack("clapB");
    clapB.takeDamage(5);
    clapB.beRepaired(3);

    return (0);
}