#include "HumanB.hpp"

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name)
{
    weapon = NULL;
    this->name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
   this->weapon = &weapon;
}