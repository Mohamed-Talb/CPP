#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon 
{
    std::string type;
    public:
        Weapon(std::string type);
        const std::string &getType(); ///??? try : std::string const &
        void setType(std::string Value);
};

#endif