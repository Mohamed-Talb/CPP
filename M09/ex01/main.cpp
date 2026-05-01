#include "RPN.hpp"

int main(int ac, char **av)
{
    RPN rpn;
    std::string RPNSring;
    for (int i = 1; i < ac; i++)
    {
        RPNSring += av[i];
    }
    try
    {
        std::cout << rpn.execute(RPNSring) << std::endl;
    }
    catch (std::exception *err)
    {
        std::cout << err->what() << std::endl;
    }
}