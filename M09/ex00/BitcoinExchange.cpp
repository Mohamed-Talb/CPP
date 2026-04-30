#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(std::string DBPath)
{
    
}

std::string BitcoinExchange::readDB(std::string DBPath)
{
    std::ifstream DBFile(DBPath);
    if (DBFile.is_open() == false)
        std::cerr << "Error Opening file: " + DBPath << std::endl;
    std::string line;
    int cutPosition;
    std::string date;
    std::string price;
    while (std::getline(DBFile, line))
    {
        cutPosition = line.find(",");
        date = line.substr(0, cutPosition);
        price = line.substr(cutPosition + 1, line.length());
    }
}
void BitcoinExchange::printExchangeHistory()
{

}