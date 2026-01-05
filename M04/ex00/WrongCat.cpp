#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called" << std::endl;
}

WrongCat::WrongCat(std::string Type) : WrongAnimal(Type)
{
    std::cout << "WrongCat Parameterized Constructor Called " << std::endl;
}

WrongCat::WrongCat(const WrongCat &C) : WrongAnimal(C)
{
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
}

const WrongCat &WrongCat::operator=(const WrongCat &A)
{
    std::cout << "WrongCat Copy Assignment Operator Called" << std::endl;
    if (this != &A)
    {
        WrongAnimal::operator=(A);
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Meoo" << std::endl;
}