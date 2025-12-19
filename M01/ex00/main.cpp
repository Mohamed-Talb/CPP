#include "Zombie.hpp"

int main()
{
    std::string name = "Walker1";
    Zombie *newZ = newZombie(name);
    newZ->announce();
    randomChump("Tyler2"); // malloc and new with obj placment new 
    delete newZ; // delete with distructor 
}