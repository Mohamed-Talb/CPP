#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <cmath>
#include <climits>

enum Type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};

class ScalarConvert
{
	private:
	ScalarConvert();
	ScalarConvert(ScalarConvert &other);
	~ScalarConvert();
	ScalarConvert &operator=(ScalarConvert &other);
	public:
	static void convert(std::string param);
};

#endif