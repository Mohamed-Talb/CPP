#include "Zombie.hpp"

int main()
{
    std::string name = "mohamed"; /// ???????????????????? NULL
    int N = 10; // negative
    Zombie *ZombiesH = zombieHorde(N, name);
    delete[] ZombiesH; // how delete know the size of freeing 
    for (int i = 0; i < N; i++)
    {
        ZombiesH[i].announce();
    }
}