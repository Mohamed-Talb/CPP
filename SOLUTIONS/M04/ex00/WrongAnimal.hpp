#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(std::string Type);
        WrongAnimal(const WrongAnimal &A);
        const WrongAnimal &operator=(const WrongAnimal &A);
        std::string getType() const;
        void makeSound() const;
};

#endif