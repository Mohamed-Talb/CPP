#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include "stack"

class RPN
{
    private:
    RPN(RPN &r);
    void operator=(RPN &r);
    public:
    RPN();
    ~RPN();
    int execute(std::string RPNString);
};

#endif