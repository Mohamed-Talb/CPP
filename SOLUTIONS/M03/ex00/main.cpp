#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap defaultClap;
    std::cout << std::endl;
    ClapTrap hero("Clappy");
    std::cout << std::endl;

    hero.attack("Target1");
    hero.attack("Target2");
    std::cout << std::endl;

    hero.takeDamage(5); 
    hero.takeDamage(10); 
    std::cout << std::endl;

    hero.beRepaired(3); 
    hero.beRepaired(10);
    std::cout << std::endl;

    ClapTrap weakHero("Weakling");
    for (int i = 0; i < 12; i++) 
    {
        weakHero.attack("Dummy");
    }
    std::cout << std::endl;

    ClapTrap copyHero(hero);
    copyHero.attack("CopyTarget");
    std::cout << std::endl;

    ClapTrap assignedHero;
    assignedHero = hero;
    assignedHero.beRepaired(2);
    std::cout << std::endl;
    std::cout << "=== End of ClapTrap tests ===" << std::endl;
    return 0;
}
