#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    int size = 10; // odd size 
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
    const Animal *animals[size];
    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    std::cout << animals[9]->getType() << " " << std::endl;
    std::cout << animals[10]->getType() << " " << std::endl;
    for (int i = 0; i < size; i++)
    {
        animals[i]->makeSound();
    }
    for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }
}
