#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    Brain *brain;
    public:
        Dog();
        ~Dog();
        Dog(std::string Type);
        Dog(const Dog &A);
        const Dog &operator=(const Dog &A);
        void makeSound() const;  
};

#endif