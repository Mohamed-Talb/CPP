#include <iostream>

class Zombie
{
    std::string Name;
    void announce(void);
    Zombie* newZombie( std::string name );
    void randomChump( std::string name );
}