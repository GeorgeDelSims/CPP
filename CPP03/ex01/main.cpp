#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // ClapTrap    clapA = ClapTrap("clapA");
    // ClapTrap    clapB = ClapTrap("clapB");
    ScavTrap    scavA = ScavTrap("scavA");
    ScavTrap    scavB = ScavTrap("scavB");

    // clapA.attack("clapB");
    // clapB.takeDamage(5);
    // clapB.beRepaired(3);

    scavA.attack("scavB");
    scavB.takeDamage(5);
    scavA.beRepaired(3);

    return (0);
}
