#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{
    // std::cout << "Ice Default Constructor Called" << std::endl;
}
Ice::Ice(const Ice &IC) : AMateria(IC)
{
    (void)IC;
    // std::cout << "Ice Copy Constructor Called" << std::endl;
}

const Ice &Ice::operator=(const Ice &IC)
{
    (void)IC;
    // std::cout << "Ice Copy Assignment Operator Called" << std::endl;
    return *this;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

Ice::~Ice()
{
    // std::cout << "Ice Destructor Called" << std::endl;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return;
}
