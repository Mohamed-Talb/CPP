#include "BitcoinExchange.hpp"

#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

static std::string trim(const std::string &str)
{
    std::size_t start = 0;
    std::size_t end = str.size();

    while (start < end && std::isspace(static_cast<unsigned char>(str[start])))
        ++start;

    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
        --end;

    return str.substr(start, end - start);
}

static bool allIsDigits(const std::string &str)
{
    if (str.empty())
        return false;

    for (std::size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }

    return true;
}

static bool isValidDate(const std::string &date)
{
    const std::size_t FIRST_DASH_POSITION = 4;
    const std::size_t SECOND_DASH_POSITION = 7;

    if (date.length() != 10 || date[FIRST_DASH_POSITION] != '-' || date[SECOND_DASH_POSITION] != '-')
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (!allIsDigits(year) || !allIsDigits(month) || !allIsDigits(day))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    int yearValue = std::atoi(year.c_str());
    int monthValue = std::atoi(month.c_str());
    int dayValue = std::atoi(day.c_str());

    if (yearValue < 2009 || monthValue < 1 || monthValue > 12)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    int daysInMonth[] = 
    {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    bool isLeapYear = (yearValue % 4 == 0 && yearValue % 100 != 0) || yearValue % 400 == 0;

    if (isLeapYear)
        daysInMonth[1] = 29;
    if (dayValue < 1 || dayValue > daysInMonth[monthValue - 1])
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }
    return true;
}

static bool isValidValue(const std::string &value)
{
    if (value.empty())
    {
        std::cout << "Error: invalid number." << std::endl;
        return false;
    }

    errno = 0;
    char *end = NULL;
    double number = std::strtod(value.c_str(), &end);
    if (errno == ERANGE || end == value.c_str() || *end != '\0')
    {
        std::cout << "Error: invalid number." << std::endl;
        return false;
    }
    if (number < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (number > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void readDatabase(const std::string &databasePath, BitcoinPrices &bitcoinPrices)
{
    std::ifstream databaseFile(databasePath.c_str());
    if (!databaseFile.is_open())
        throw std::runtime_error("Error: opening file: " + databasePath);

    std::string line;
    if (!std::getline(databaseFile, line))
        throw std::runtime_error("Error: empty database file.");

    while (std::getline(databaseFile, line))
    {
        std::size_t commaPosition = line.find(',');
        if (commaPosition == std::string::npos)
            continue;
        std::string date = line.substr(0, commaPosition);
        std::string price = line.substr(commaPosition + 1);

        if (date.empty() || price.empty())
            continue;
        bitcoinPrices[date] = price;
    }
}

double getPriceFromDatabase(const BitcoinPrices &bitcoinPrices, const std::string &date)
{
    if (bitcoinPrices.empty())
        throw std::runtime_error("Error: empty database.");

    BitcoinPrices::const_iterator it = bitcoinPrices.lower_bound(date);
    if (it == bitcoinPrices.end() || it->first != date)
    {
        if (it == bitcoinPrices.begin())
            throw std::runtime_error("Error: no price available for this date.");
        --it;
    }
    return std::atof(it->second.c_str());
}

void processInputFile(const std::string &inputPath, const BitcoinPrices &bitcoinPrices)
{
    std::ifstream inputFile(inputPath.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Error: could not open file.");
    std::string line;
    if (!std::getline(inputFile, line))
        throw std::runtime_error("Error: empty input file.");

    while (std::getline(inputFile, line))
    {
        std::size_t pipePosition = line.find('|');
        if (pipePosition == std::string::npos || line.find('|', pipePosition + 1) != std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = trim(line.substr(0, pipePosition));
        std::string value = trim(line.substr(pipePosition + 1));
        if (date.empty() || value.empty())
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isValidDate(date))
            continue;
        if (!isValidValue(value))
            continue;
        try
        {
            double price = getPriceFromDatabase(bitcoinPrices, date);
            double amount = std::atof(value.c_str());
            std::cout << date << " => "<< value << " = " << price * amount << std::endl;
        }
        catch (const std::exception &exception)
        {
            std::cout << exception.what() << std::endl;
        }
    }
}

void BitcoinExchange(const std::string &databasePath, const std::string &inputPath)
{
    BitcoinPrices bitcoinPrices;
    readDatabase(databasePath, bitcoinPrices);
    processInputFile(inputPath, bitcoinPrices);
}