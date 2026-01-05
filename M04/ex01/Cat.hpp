#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    Brain *brain;
    public:
        Cat();
        ~Cat();
        Cat(std::string Type);
        Cat(const Cat &A);
        const Cat &operator=(const Cat &A);
        
        void makeSound() const;
        void getIdea();
        void FillIdeas(std::string Idea);
};

#endif