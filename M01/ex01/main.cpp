#include "Zombie.hpp"

int main()
{
    std::string name = "Rachid";
    int N = 10;
    Zombie *ZombiesH = zombieHorde(N, name);
    if (!ZombiesH) 
        return 1;
    for (int i = 0; i < N; i++)
    {
        ZombiesH[i].announce();
    }
    delete[] ZombiesH;
}
