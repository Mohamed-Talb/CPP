#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal Default Constructor Called" << std::endl;
}
Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}
Animal::Animal(std::string Type) 
{
    type = Type;
    std::cout << "Animal Parameterized Constructor Called " << std::endl;
}
Animal::Animal(const Animal &A)
{
    type = A.type;
    std::cout << "Animal Copy Constructor Called" << std::endl;
}
const Animal &Animal::operator=(const Animal &A)
{
    std::cout << "Animal Copy Assignment Operator Called" << std::endl;
    if (this != &A)
    {
        this->type = A.type;
    }
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}