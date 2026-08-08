#include "Character.hpp"

Character::Character()
{
    for (int i = 0;i < 4; i++)
    {
        MInvantory[i] = NULL;
    }
    // std::cout << "Character Default Constructor Called" << std::endl;
}

Character::Character(const Character& other) : Name(other.Name)
{
    for (int i = 0; i < 4; i++)
    {
        if (MInvantory[i])
        {
            delete MInvantory[i];
            MInvantory[i] = NULL;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (other.MInvantory[i])
            MInvantory[i] = other.MInvantory[i]->clone();
    }
}

Character::Character(std::string const &N)
{
    Name = N;
    for (int i = 0;i < 4; i++)
    {
        MInvantory[i] = NULL;
    }
    // std::cout << "Character Parametriazed Constructor Called" << std::endl;
}
const Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        Name = other.Name;
        for (int i = 0; i < 4; i++)
        {
            if (MInvantory[i])
            {
                delete MInvantory[i];
                MInvantory[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (other.MInvantory[i])
                MInvantory[i] = other.MInvantory[i]->clone();
        }
    }
    // std::cout << "Character Copy Assignment Operator Called" << std::endl;
    return *this;
}

std::string const &Character::getName() const
{
    return Name;
}

void Character::setName(std::string &N)
{
    Name = N;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (MInvantory[i])
            delete MInvantory[i];
    }
    // std::cout << "Character Destructor Called" << std::endl;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!MInvantory[i])
        {
            MInvantory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    MInvantory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !MInvantory[idx])
        return;
    MInvantory[idx]->use(target);
}
