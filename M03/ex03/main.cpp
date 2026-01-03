#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    ClapTrap clap("Clappy");
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    ScavTrap scav("Scavvy");
    scav.attack("Target2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    FragTrap frag("Fraggy");
    frag.attack("Target3");
    frag.takeDamage(15);
    frag.beRepaired(5);
    frag.highFivesGuys();

    std::cout << std::endl << std::endl;
    DiamondTrap diamond("Diamondy");
    diamond.attack("Target4");

    diamond.highFivesGuys();  // from FragTrap
    diamond.guardGate();       // from ScavTrap
    diamond.whoAmI();          // DiamondTrap's own function

    std::cout << "\n--- Copy DiamondTrap ---" << std::endl;
    DiamondTrap copyDiamond(diamond);
    copyDiamond.whoAmI();

    std::cout << "\n--- Assign DiamondTrap ---" << std::endl;
    DiamondTrap assignDiamond;
    assignDiamond = diamond;
    assignDiamond.whoAmI();
    return 0;
}
