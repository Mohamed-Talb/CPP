#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
    // std::cout << "Cure Default Constructor Called" << std::endl;
}
Cure::Cure(const Cure &CR) : AMateria(CR)
{
    (void)CR;
    // std::cout << "Cure Copy Constructor Called" << std::endl;
    return ;
}

const Cure &Cure::operator=(const Cure &CR)
{
    (void)CR;
    // std::cout << "Cure Copy Assignment Operator Called" << std::endl;
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

Cure::~Cure()
{
    // std::cout << "Cure Destructor Called" << std::endl;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *"<< std::endl;
}