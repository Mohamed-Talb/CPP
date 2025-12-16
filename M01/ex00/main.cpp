#include "Zombie.hpp"

int main()
{
    std::string name = "Walker1";
    Zombie *newZ = newZombie(name);
    randomChump("Tyler2");
    delete newZ;
}