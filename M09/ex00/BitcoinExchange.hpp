#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
private:
    std::map<std::string, std::string> bitcoinPrices;

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& DBPath);
    ~BitcoinExchange();

    void readDB(const std::string& DBPath);
    double getPriceFromDB(const std::string& date);
    void printExchangeHistory(const std::string& filePath);
};

#endif