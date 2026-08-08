#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    this->Name = name;
    std::cout << "ClapTrap Parameterized Constructor Called " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &Clap)
{
    this->Name = Clap.Name;
    this->AttackDamage = Clap.AttackDamage;
    this->HitPoints = Clap.HitPoints;
    this->EnergyPoints = Clap.EnergyPoints;
    std::cout << "ClapTrap Copy Constructor Called" << std::endl;
}

const ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy Assignment Operator Called" << std::endl;
    if (this != &other)
    {
        this->Name = other.Name;
        this->AttackDamage = other.AttackDamage;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;  
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor Called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (EnergyPoints == 0)
        std::cout << "ClapTrap " << Name << " Dont Have Enought Energy Points" << std::endl;
    else if (HitPoints == 0)
        std::cout << "ClapTrap " << Name << " Die!" << std::endl;
    else
    {
        EnergyPoints--;
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl; 
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints == 0)
    {
        std::cout << "ClapTrap " << Name << " Die!" << std::endl;
        return ;
    }
    if (amount > HitPoints)
        amount = HitPoints;
    HitPoints -= amount;
    std::cout << "ClapTrap " << Name << " Take damage " << amount << std::endl;  
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (EnergyPoints == 0)
    {
        std::cout << "ClapTrap " << Name << " Dont Have Enought Energy Points" << std::endl; 
        return ;
    }
    if (HitPoints == 0)
    {
        std::cout << "ClapTrap " << Name << " Die!" << std::endl;
        return ;
    }
    EnergyPoints--; 
    HitPoints += amount;
    std::cout << "ClapTrap " << Name << " be Repaired " << amount << std::endl;  
}