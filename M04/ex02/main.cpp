#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    int size = 10;
    // Animal animal; // ERROR

    Animal* j = new Dog();
    Animal* i = new Cat();
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
    std::cout << std::endl << std::endl;
    std::cout << animals[4]->getType() << " " << std::endl;
    std::cout << animals[5]->getType() << " " << std::endl;
    for (int i = 0; i < size; i++)
    {
        animals[i]->makeSound();
    }
    for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }
}
