#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        int result = RPN(argv[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception &exception)
    {
        std::cerr << exception.what() << std::endl;
        return 1;
    }

    return 0;
}