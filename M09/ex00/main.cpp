#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        std::cout << "Error: Invalid Arguments" << std::endl;
    std::string DBPath = "./data.csv";
    BitcoinExchange Bit(DBPath);
    try
    {
        Bit.printExchangeHistory(av[1]);
    }
    catch (std::exception *err)
    {
        std::cout << err->what() << std::endl;
    }
}