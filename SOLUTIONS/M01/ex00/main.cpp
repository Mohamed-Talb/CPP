#include "Zombie.hpp"

int main()
{
    std::string name = "Walker1";
    Zombie *newZ = newZombie(name);
    newZ->announce();
    randomChump("Tyler1");
    delete newZ;
}