#include "AMateria.hpp"

AMateria::AMateria()
{
    // std::cout << "AMateria Default Constructor Called" << std::endl;
}
AMateria::AMateria(const AMateria &AM)
{
    type = AM.type;
    // std::cout << "AMateria Copy Constructor Called" << std::endl;
}
AMateria::AMateria(std::string const &T) : type(T)
{
    // std::cout << "AMateria Parametriazed Constructor Called" << std::endl;
}

const AMateria& AMateria::operator=(const AMateria &AM)
{
    if (this != &AM)
        type = AM.type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    return;
}

AMateria::~AMateria()
{
    // std::cout << "AMateria Destructor Called" << std::endl;
}
