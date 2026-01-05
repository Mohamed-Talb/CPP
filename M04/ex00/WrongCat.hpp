#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(std::string Type);
        WrongCat(const WrongCat &A);
        const WrongCat &operator=(const WrongCat &A);
        void makeSound() const;
};

#endif