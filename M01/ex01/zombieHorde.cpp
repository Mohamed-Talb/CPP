#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombiesArr = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombiesArr[i].setName(name);
    }
    return zombiesArr;
}