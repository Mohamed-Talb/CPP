#include <iostream>
#include <iomanip>
#include <cmath>
#include "ScalarConvert.hpp"
// 1 = char
// 2 = int
// 3 = float
// 4 = double
Type getType(std::string &input)
{
    if (input.length() == 1 && !isdigit(input[0]))
        return CHAR;
    char *endptr;
    double value = std::strtod(input.c_str(), &endptr);
    if (endptr == input.c_str())
        return INVALID;
	if ((std::isnan(value) || std::isinf(value)) && (*endptr == 'f' || *(endptr + 1) == '\0'))
		return PSEUDO;
    if (*endptr == '\0')
        return (input.find('.') != std::string::npos) ? DOUBLE : INT;
    if (*endptr == 'f' && *(endptr + 1) == '\0')
        return FLOAT;
    return INVALID;
}

void Chars(std::string &cInput)
{
	std::cout << "char: " << cInput[0] << std::endl;
	std::cout << "int:  " << static_cast<int>(cInput[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(cInput[0]) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(cInput[0]) << std::endl;
}
void Integers(std::string &cInput)
{
	int value = strtod(cInput.c_str(), NULL);
	char C = static_cast<char>(value);
	if (std::isprint(C))
		std::cout << "char: " << C << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int:  " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}
void Floats(std::string &cInput)
{
	float value = strtof(cInput.c_str(), NULL);
	char C = static_cast<char>(value);
	if (std::isprint(C))
		std::cout << "char: " << C << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int:  " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << value << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
	std::cout << "floats" << std::endl;	
}
void Doubles(std::string &cInput)
{
	double value = strtod(cInput.c_str(), NULL);
	char C = static_cast<char>(value);
	if (std::isprint(C))
		std::cout << "char: " << C << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int:  " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;
	std::cout << "double: " << value << std::endl;
	
}

void Pseudos(std::string &cInput)
{
	double value = std::strtod(cInput.c_str(), NULL);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << value << 'f' << std::endl;
	std::cout << "double: " << value << std::endl;
}

void convert(std::string param)
{
	Type inputType = getType(param);
	if (inputType == INVALID)
		std::cout << "invalid" << std::endl;
	else if (inputType == CHAR)
		Chars(param);
	else if (inputType == INT)
		Integers(param);
	else if (inputType == FLOAT)
		Floats(param);
	else if (inputType == DOUBLE)
		Doubles(param);
	else if (inputType == PSEUDO)
		Pseudos(param);
}


int main(int ac, char **av)
{
	std::cout << av[1] << std::endl;
	convert(av[1]);
}

// check if the sub of the foilt to int  and int = 0; add .0
// handle overflow
// handle if char > 127