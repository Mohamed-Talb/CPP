#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain;
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor Called" << std::endl;
}

Cat::Cat(std::string Type) : Animal(Type)
{
    std::cout << "Cat Parameterized Constructor Called " << std::endl;
}

Cat::Cat(const Cat &C) : Animal(C)
{
    this->brain = new Brain(*C.brain);
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

const Cat &Cat::operator=(const Cat &A)
{
    std::cout << "Cat Copy Assignment Operator Called" << std::endl;
    if (this != &A)
    {
        Animal::operator=(A);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meoo" << std::endl;
}