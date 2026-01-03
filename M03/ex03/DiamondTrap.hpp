#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap 
{
    std::string Name; 
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap  &DiamondTrap);
        const DiamondTrap &operator=(const DiamondTrap  &other);
        ~DiamondTrap();
        void attack(const std::string& target);
        void whoAmI();
};

#endif