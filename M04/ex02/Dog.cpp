#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain;
    std::cout << "Dog Default Constructor Called" << std::endl;
}
Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor Called" << std::endl;
}
Dog::Dog(std::string Type) : Animal(Type)
{
    std::cout << "Dog Parameterized Constructor Called " << std::endl;
}
Dog::Dog(const Dog &D) : Animal(D)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
}
const Dog &Dog::operator=(const Dog &A)
{
    std::cout << "Dog Copy Assignment Operator Called" << std::endl;
    if (this != &A)
    {
        Animal::operator=(A);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}