#include "RPN.hpp"

RPN::RPN(RPN &r) {(void)r;}
void RPN::operator=(RPN &r) {(void)r;}
RPN::RPN() {}
RPN::~RPN() {}

static int apllyOperation(int left, char op, int right)
{
    if (op == '+')
        return left + right;
    else if (op == '-')
        return left - right;
    else if (op == '*')
        return left * right;
    else
    {
        if (right == 0)
            throw new std::runtime_error("Error");
        return left / right;
    }
}

int RPN::execute(std::string RPNString) 
{
    size_t RPNLen = RPNString.length();
    std::stack<int> numbersStack;
    int left, right;
    size_t result;
    if (RPNString.empty())
        throw new std::runtime_error("Error");
    for (size_t i = 0; i < RPNLen; i++)
    {
        char curr =  RPNString[i];
        if (curr == '+' || curr == '-' || curr == '/' || curr == '*')
        {
            if (numbersStack.size() < 2)
                throw new std::runtime_error("Error");
            right = numbersStack.top();
            numbersStack.pop();
            left  = numbersStack.top();
            numbersStack.pop();
            result = apllyOperation(left, curr, right);
            numbersStack.push(result);
        }
        else if (std::isdigit(curr))
        {
            if (i != 0 && i != RPNLen - 1)
                if (!std::isspace(RPNString[i + 1]) || !std::isspace(RPNString[i - 1]))
                    throw new std::runtime_error("Error");
            numbersStack.push(curr - '0');
        }
        else if (std::isspace(curr))
            continue;
        else 
            throw new std::runtime_error("Error");
    }
    if (numbersStack.size() != 1)
        throw new std::runtime_error("Error");
    return numbersStack.top();
}