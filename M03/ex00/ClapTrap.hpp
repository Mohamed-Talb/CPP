#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>


class ClapTrap
{
   std::string Name;
   unsigned int HitPoints;
   unsigned int EnergyPoints;
   unsigned int AttackDamage;
   public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &Clap);
        const ClapTrap &operator=(const ClapTrap &other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif 