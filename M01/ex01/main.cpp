#include "Zombie.hpp"

int main()
{
    std::string name = "Walker1";
    int N = 10;
    Zombie *ZombiesH = zombieHorde(N, name);
    for (int i = 0; i < N; i++)
    {
        ZombiesH[i].announce();
    }
}