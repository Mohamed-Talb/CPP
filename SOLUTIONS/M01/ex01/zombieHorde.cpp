#include "Zombie.hpp"

Zombie* zombieHorde(int N, const std::string name)
{
    if (N <= 0) 
    {
        std::cerr << "ERROR: Horde size must be positive" << std::endl;
        return NULL;
    }
    Zombie* zombiesArr = new Zombie[N];
    for (int i = 0; i < N; i++) 
    {
        zombiesArr[i].setName(name);
    }
    return zombiesArr;
}
