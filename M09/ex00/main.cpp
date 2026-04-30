#include "BitcoinExchange.hpp"


std::string readDB(std::string DBPath)
{
    std::ifstream DBFile(DBPath);
    if (DBFile.is_open() == false)
    {
        std::cerr << "Error Opening file: " + DBPath << std::endl;
        return "";
    }
    std::string line;
    int cutPosition;
    std::string date;
    std::string price;
    std::getline(DBFile, line);
    while (std::getline(DBFile, line))
    {
        std::cout << line << std::endl; 
        cutPosition = line.find(",");
        date = line.substr(0, cutPosition);
        price = line.substr(cutPosition + 1, line.length());
        // std::cout << date << " \\ " << price << std::endl;
    }
}


int main()
{
    readDB("./data.csv");
}