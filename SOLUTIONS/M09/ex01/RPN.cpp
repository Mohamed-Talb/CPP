#include "RPN.hpp"

static int applyOperation(int left, char operation, int right)
{
    if (operation == '+')
        return left + right;

    if (operation == '-')
        return left - right;

    if (operation == '*')
        return left * right;

    if (operation == '/')
    {
        if (right == 0)
            throw std::runtime_error("Error");

        return left / right;
    }

    throw std::runtime_error("Error");
}

int RPN(const std::string &expression)
{
    if (expression.empty())
        throw std::runtime_error("Error");

    std::stringstream stream(expression);
    std::stack<int> numbers;
    std::string token;

    while (stream >> token)
    {
        if (token.size() != 1)
            throw std::runtime_error("Error");

        char current = token[0];
        if (std::isdigit(static_cast<unsigned char>(current)))
        {
            numbers.push(current - '0');
            continue;
        }
        if (current != '+' && current != '-' && current != '*' && current != '/')
            throw std::runtime_error("Error");
        if (numbers.size() < 2)
            throw std::runtime_error("Error");
        int right = numbers.top();
        numbers.pop();
        int left = numbers.top();
        numbers.pop();
        numbers.push(applyOperation(left, current, right));
    }
    if (numbers.size() != 1)
        throw std::runtime_error("Error");

    return numbers.top();
}