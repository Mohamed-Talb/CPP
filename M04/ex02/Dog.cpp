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
    brain = new Brain();
    std::cout << "Dog Parameterized Constructor Called " << std::endl;
}
Dog::Dog(const Dog &D) : Animal(D)
{
    this->brain = new Brain(*D.brain);
    std::cout << "Dog Copy Constructor Called" << std::endl;
}
const Dog &Dog::operator=(const Dog &A)
{
    std::cout << "Dog Copy Assignment Operator Called" << std::endl;
    if (this != &A)
    {
        Animal::operator=(A);
        delete brain;
        brain = new Brain(*A.brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}


void Dog::FillIdeas(std::string Idea)
{
    for (int i = 0; i < 100; i++)
    {
        brain->Ideas[0] = Idea;
    }
}

void Dog::getIdea()
{
    std::cout << "The Brain Full By " << brain->Ideas[0] << std::endl;
}