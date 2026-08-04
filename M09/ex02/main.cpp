#include "PmergeMe.hpp"


template <typename Container>
void printSequence(const Container &sequence)
{
    typename Container::const_iterator it = sequence.begin();
    while (it != sequence.end())
    {
        std::cout << *it;
        ++it;
        if (it != sequence.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

static bool parseArguments(int argc, char **argv, IntVector &numbers)
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

int main(int argc, char **argv)
{
    IntVector input;

    if (!parseArguments(argc, argv, input))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    IntVector vectorSequence(input.begin(), input.end());
    IntDeque dequeSequence(input.begin(), input.end());

    std::cout << "Before: ";
    printSequence(input);

    std::clock_t vectorStart = std::clock();
    IntVector sortedVector = fordJohnson(vectorSequence);
    std::clock_t vectorEnd = std::clock();

    std::clock_t dequeStart = std::clock();
    IntDeque sortedDeque = fordJohnson(dequeSequence);
    std::clock_t dequeEnd = std::clock();

    double vectorTime = static_cast<double>(vectorEnd - vectorStart) * 1000000.0 / CLOCKS_PER_SEC;
    double dequeTime = static_cast<double>(dequeEnd - dequeStart) * 1000000.0 / CLOCKS_PER_SEC;

    std::cout << "After:  ";
    printSequence(sortedVector);

    std::cout << std::fixed << std::setprecision(3);

    std::cout << "Time to process a range of " << vectorSequence.size();
    std::cout << " elements with std::vector: " << vectorTime << " us" << std::endl;

    std::cout << "Time to process a range of " << dequeSequence.size();
    std::cout << " elements with std::deque:  " << dequeTime << " us" << std::endl;

    return 0;
}