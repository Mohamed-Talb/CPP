#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>
#include <map>

class BitcoinExchange
{
	std::map<std::string, int> bitcoinPrices;
    public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(std::string DBPath);
    
    std::string readDB(std::string DBPath);
    void printExchangeHistory();
};

#endif