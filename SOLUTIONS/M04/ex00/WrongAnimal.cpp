#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string Type) 
{
    type = Type;
    std::cout << "WrongAnimal Parameterized Constructor Called " << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &A)
{
    type = A.type;
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}
const WrongAnimal &WrongAnimal::operator=(const WrongAnimal &A)
{
    std::cout << "WrongAnimal Copy Assignment Operator Called" << std::endl;
    if (this != &A)
    {
        this->type = A.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}