#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        Ideas[i] = "Have No Idea!";
    }
    std::cout << "Brain Default Constructor Called" << std::endl;
}
Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}
Brain::Brain(std::string Idea) 
{
    for (int i = 0; i < 100; i++)
    {
        Ideas[i] = Idea;
    }
    std::cout << "Brain Parameterized Constructor Called " << std::endl;
}

Brain::Brain(const Brain &B)
{
    for (int i = 0; i < 100; i++)
    {
        this->Ideas[i] = B.Ideas[i];
    }
    std::cout << "Brain Copy Constructor Called" << std::endl;
}

const Brain &Brain::operator=(const Brain &B)
{
    std::cout << "Brain Copy Assignment Operator Called" << std::endl;
    if (this != &B)
    {
        *this = Brain(B);
    }
    return *this;
}

void Brain::FillIdeas(std::string Idea)
{
    for (int i = 0; i < 100; i++)
    {
        Ideas[i] = Idea;
    }
}