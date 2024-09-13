#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    // ClapTrap    clapA = ClapTrap("clapA");
    // ClapTrap    clapB = ClapTrap("clapB");
    ScavTrap    scavA = ScavTrap("scavA");
    ScavTrap    scavB = ScavTrap("scavB");
    FragTrap    fragC = FragTrap("fragC");
    FragTrap    fragD = FragTrap("fragD");

    fragC.attack("scavB");
    fragC.highFivesGuys();
    fragD.takeDamage(5);
    fragD.beRepaired(3);


    scavA.attack("scavB");
    scavA.guardGate();
    scavB.takeDamage(5);
    scavA.beRepaired(3);

    return (0);
}
