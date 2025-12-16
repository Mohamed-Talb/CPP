#include "Weapon.hpp"

const std::string &Weapon::getType()
{
    const std::string &typeRef = type;
    return typeRef; 
}

void Weapon::setType(std::string Value)
{
    type = Value;
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}