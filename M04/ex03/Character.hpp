#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        AMateria *MInvantory[4];
        std::string Name;
    public:
    Character();
    ~Character();
    Character(const Character &CH);
    Character(std::string const &N);
    const Character &operator=(const Character &CH);

    std::string const & getName() const;
    void setName(std::string &N);
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif