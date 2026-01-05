#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
    Ice();
    ~Ice();
    Ice(const Ice &AM);
    const Ice&operator=(const Ice &AM);

    std::string const & getType() const;
    AMateria* clone() const;
    void use(ICharacter& target);  
};

#endif