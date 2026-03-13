#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert() {};
ScalarConvert::ScalarConvert(ScalarConvert &) {};
ScalarConvert::~ScalarConvert() {};
ScalarConvert &ScalarConvert::operator=(ScalarConvert &){return *this;};



Type getType(const std::string& input)
{
    if (input.length() == 1 && !isdigit(input[0]))
        return CHAR;
    char* end;
    double value = strtod(input.c_str(), &end);
    if (end == input.c_str())
        return INVALID;
    if ((std::isnan(value) || std::isinf(value)) &&
        (*end == 'f' || *end == '\0'))
        return PSEUDO;
    if (*end == '\0')
        return (input.find('.') != std::string::npos) ? DOUBLE : INT;
    if (*end == 'f' && *(end + 1) == '\0')
        return FLOAT;
    return INVALID;
}

void printChar(double value)
{
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(value) << std::endl;
}

void printInt(double value)
{
    if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void printFloat(double value, std::string input)
{
	std::string precision = (value - strtod(input.c_str(), NULL) == 0 && !std::isnan(value) && !std::isinf(value)) ? ".0f" : "f";
	std::cout << "float: " << static_cast<float>(value) << precision << std::endl;
}

void printDouble(double value, std::string input)
{
	std::string precision = (value - strtod(input.c_str(), NULL) == 0 && !std::isnan(value) && !std::isinf(value)) ? ".0" : "";
    std::cout << "double: " << value << precision <<  std::endl;
}

void ScalarConvert::convert(std::string param)
{
    Type type = getType(param);
    if (type == INVALID)
    {
        std::cerr << "Invalid input" << std::endl;
        return ;
    }
    double value;
    if (type == CHAR)
        value = param[0];
    else
        value = strtod(param.c_str(), NULL);
    printChar(value);
    printInt(value);
    printFloat(value, param);
    printDouble(value, param);
}