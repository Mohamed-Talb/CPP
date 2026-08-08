#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
    Cure();
    ~Cure();
    Cure(const Cure &AM);
    const Cure&operator=(const Cure &AM);

    AMateria* clone() const;
    void use(ICharacter& target);  
};

#endif