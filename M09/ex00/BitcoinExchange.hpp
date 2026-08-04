#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <cctype>


typedef std::map<std::string, std::string> BitcoinPrices;
void BitcoinExchange(const std::string &databasePath, const std::string &inputPath);

#endif