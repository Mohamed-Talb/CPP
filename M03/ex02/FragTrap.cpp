#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap Default Constructor Called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap Parameterized Constructor Called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &Scav) : ClapTrap(Scav)
{
    std::cout << "FragTrap Copy Constructor Called" << std::endl;
}

const FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap Copy Assignment Operator Called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other); 
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor Called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << ": high-fives" << std::endl;
}
