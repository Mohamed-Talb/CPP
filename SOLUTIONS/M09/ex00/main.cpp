#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid number of arguments." << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange("data.csv", argv[1]);
    }
    catch (const std::exception &exception)
    {
        std::cerr << exception.what() << std::endl;
        return 1;
    }

    return 0;
}