#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(std::string Type);
        Cat(const Cat &A);
        const Cat &operator=(const Cat &A);
        void makeSound() const;
};

#endif