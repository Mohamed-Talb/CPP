#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(std::string Type);
        Animal(const Animal &A);
        const Animal &operator=(const Animal &A);
        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif