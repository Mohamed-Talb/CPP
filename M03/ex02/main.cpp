#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap Clap("Clap");
    ScavTrap Scav("Scav");
    FragTrap Frag("Frag");
    FragTrap Frag1;

    Clap.attack("mohamed");
    Scav.attack("mohamed");
    Frag.attack("mohamed");
    Frag.beRepaired(55);
    Frag.takeDamage(550);
    Frag = Frag1;
    Frag.attack("mohamed");
}