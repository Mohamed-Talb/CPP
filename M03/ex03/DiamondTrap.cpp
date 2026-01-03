#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 30;
    std::cout << "DiamondTrap Default Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
    this->Name = name;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 30;
    std::cout << "DiamondTrap Parameterized Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap  &DiamondTrap) : ClapTrap(DiamondTrap), ScavTrap(DiamondTrap), FragTrap(DiamondTrap)
{
    this->Name = DiamondTrap.Name;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

const DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap Copy Assignment Operator Called" << std::endl;
    if (this != &other)
    {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->Name = other.Name;
    }
    return *this;
}


DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor Called for " << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << Name
              << ", ClapTrap name: " << ClapTrap::Name << std::endl;
}
