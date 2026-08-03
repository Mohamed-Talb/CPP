#include "PmergeMe.hpp"

bool parseArguments(int argc, char **argv, IntVector &numbers)
{
    if (argc < 2)
        return false;

    std::string input;

    for (int i = 1; i < argc; ++i)
    {
        if (i > 1)
            input += " ";

        input += argv[i];
    }

    std::stringstream stream(input);
    std::string token;
    std::set<int> existingNumbers;

    while (stream >> token)
    {
        for (std::string::size_type i = 0; i < token.size(); ++i)
        {
            if (token[i] < '0' || token[i] > '9')
                return false;
        }

        errno = 0;

        char *end = NULL;
        long number = std::strtol(token.c_str(), &end, 10);

        if (errno == ERANGE || *end != '\0')
            return false;
        if (number <= 0 || number > INT_MAX)
            return false;
        int value = static_cast<int>(number);
        if (existingNumbers.find(value) != existingNumbers.end())
            return false;
        if (std::find(numbers.begin(), numbers.end(), value) != numbers.end())
            return false;
        existingNumbers.insert(value);
        numbers.push_back(value);
    }

    return !numbers.empty();
}