#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& DBPath)
{
    readDB(DBPath);
}

void BitcoinExchange::readDB(const std::string &DBPath)
{
    std::ifstream DBFile(DBPath.c_str());

    if (!DBFile.is_open())
        throw std::runtime_error("Error: Opening file: " + DBPath);

    std::string line;
    std::getline(DBFile, line);

    while (std::getline(DBFile, line))
    {
        if (line.length() < 12)
            continue;

        std::string date = line.substr(0, 10);
        std::string price = line.substr(11);
        bitcoinPrices[date] = price;
    }
}

static int allIsDigits(const std::string &str)
{
    if (str.empty())
        return 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return 0;
    }
    return 1;
}

static int isValidDate(const std::string &date)
{
    const int FIRST_DASH_POSITION = 4;
    const int SECOND_DASH_POSITION = 7;

    if (date.length() != 10 || date[FIRST_DASH_POSITION] != '-' || date[SECOND_DASH_POSITION] != '-')
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return 0;
    }

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (!allIsDigits(year) || !allIsDigits(month) || !allIsDigits(day))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return 0;
    }

    int yearValue = std::atoi(year.c_str());
    int monthValue = std::atoi(month.c_str());
    int dayValue = std::atoi(day.c_str());

    if (yearValue < 2009 || monthValue < 1 || monthValue > 12)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return 0;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((yearValue % 4 == 0 && yearValue % 100 != 0) || yearValue % 400 == 0)
        daysInMonth[1] = 29;

    if (dayValue < 1 || dayValue > daysInMonth[monthValue - 1])
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return 0;
    }
    return 1;
}

static int isValidValue(const std::string &value)
{
    if (value.empty())
    {
        std::cout << "Error: invalid number." << std::endl;
        return 0;
    }

    char* endPtr = NULL;
    double number = std::strtod(value.c_str(), &endPtr);
    if (*endPtr != '\0')
    {
        std::cout << "Error: invalid number." << std::endl;
        return 0;
    }

    if (number < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return 0;
    }
    if (number > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return 0;
    }
    return 1;
}

double BitcoinExchange::getPriceFromDB(const std::string& date)
{
    if (bitcoinPrices.empty())
        throw std::runtime_error("Error: empty database.");

    std::map<std::string, std::string>::iterator it = bitcoinPrices.lower_bound(date);

    if (it != bitcoinPrices.end() && it->first == date)
        return std::atof(it->second.c_str());

    if (it == bitcoinPrices.begin())
        throw std::runtime_error("Error: no price available for this date.");

    --it;
    return std::atof(it->second.c_str());
}

void BitcoinExchange::printExchangeHistory(const std::string& filePath)
{
    const int DATE_LENGTH = 10;
    const size_t MIN_LENGTH = 14;
    const int VALID_PIPE_POSITION = 11;

    std::ifstream inputFile(filePath.c_str());

    if (!inputFile.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(inputFile, line); // skip header: date | value

    while (std::getline(inputFile, line))
    {
        if (line.length() < MIN_LENGTH || line[VALID_PIPE_POSITION] != '|')
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, DATE_LENGTH);
        std::string value = line.substr(13);

        if (!isValidDate(date))
            continue;
        if (!isValidValue(value))
            continue;
        double price = getPriceFromDB(date);
        double amount = std::atof(value.c_str());
        double totalPrice = price * amount;
        std::cout << date << " => " << value << " = " << totalPrice << std::endl;
    }
}