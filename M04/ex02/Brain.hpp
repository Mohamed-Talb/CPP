#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
class Brain
{
    public:
    std::string Ideas[100];
    Brain();
    ~Brain();
    Brain(std::string Type);
    Brain(const Brain &A);
    const Brain &operator=(const Brain &A);
    void FillIdeas(std::string Idea);
};

#endif