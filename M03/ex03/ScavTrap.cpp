#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap Parameterized Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &Scav) : ClapTrap(Scav)
{
    std::cout << "ScavTrap Copy Constructor Called" << std::endl;
}

const ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy Assignment Operator Called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other); 
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (EnergyPoints == 0)
        std::cout << "ScavTrap " << Name << " Dont Have Enought Energy Points" << std::endl;
    else if (HitPoints == 0)
        std::cout << "ScavTrap " << Name << " Die!" << std::endl;
    else
    {
        EnergyPoints--;
        std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl; 
    }
}
