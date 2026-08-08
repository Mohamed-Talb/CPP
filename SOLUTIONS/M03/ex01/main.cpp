#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap Clap("Clap");
    ScavTrap Scav("Scav");
    ScavTrap Scav1;

    Clap.attack("mohamed");
    Scav.attack("mohamed");
    Scav.beRepaired(55);
    Scav.takeDamage(550);
    Scav = Scav1;
    Scav.attack("mohamed");
}