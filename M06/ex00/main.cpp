#include "ScalarConvert.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
	{
		std::cerr << "Invalid Arguments" << std::endl;
        return 1;
	}
    ScalarConvert::convert(av[1]);
}