#include <array>
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>




#include <algorithm>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>
#include <cstddef>

typedef std::vector<int> IntVector;
typedef std::deque<int> IntDeque;
typedef std::pair<int, int> Pair;
typedef std::vector<Pair> PairVector;



#include <cerrno>
#include <climits>
#include <cstdlib>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include "PmergeMe.hpp"
#include <deque>
#include <iostream>
#include <vector>



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


//  J(n) = J(n-1) + 2J(n-2)
//  (0, 1, 1, 3, 5, 11, 21, 43
/*
J₀ = 0 (Given)
J₁ = 1 (Given)
J₂ = 1 + 2(0) = 1
J₃ = 1 + 2(1) = 3
J₄ = 3 + 2(1) = 5
J₅ = 5 + 2(3) = 11
J₆ = 11 + 2(5) = 21
J₇ = 21 + 2(11) = 43
*/

IntVector generateJacobsthalSequence(int pairCount)
{
    IntVector jacobsthal;

    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    int index = 2;
    int current = 0;
    while (current < pairCount)
    {
        current = jacobsthal[index - 1] + 2 * jacobsthal[index - 2];
        jacobsthal.push_back(current);
        ++index;
    }
    return jacobsthal;
}

IntVector generateInsertionIndexes(const IntVector &jacobsthal, int pairCount)
{
    IntVector indexes;

    if (pairCount <= 1)
        return indexes;

    int previousBoundary = 1;
    for (size_t i = 3; i < jacobsthal.size(); ++i)
    {
        int currentBoundary = jacobsthal[i];
        if (currentBoundary > pairCount)
            currentBoundary = pairCount;
        for (int pairNumber = currentBoundary; pairNumber > previousBoundary; --pairNumber)
            indexes.push_back(pairNumber - 1);
        previousBoundary = currentBoundary;
        if (previousBoundary == pairCount)
            break;
    }

    return indexes;
}

template <typename Container>
PairVector createPairs(const Container &sequence, int &leftover, bool &hasLeftover)
{
    PairVector pairs;
    hasLeftover = sequence.size() % 2 != 0;
    size_t pairedSize = sequence.size();
    if (hasLeftover)
    {
        leftover = sequence.back();
        --pairedSize;
    }
    for (size_t i = 0; i < pairedSize; i += 2)
        pairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));

    return pairs;
}

void sortEachPair(PairVector &pairs)
{
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

template <typename Container>
Container getWinners(const PairVector &pairs)
{
    Container winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].second);
    return winners;
}

template <typename Container>
PairVector sortPairsByWinners(const PairVector &pairs, const Container &sortedWinners)
{
    PairVector sortedPairs;
    typename Container::const_iterator winnerIt = sortedWinners.begin();

    while (winnerIt != sortedWinners.end())
    {
        for (std::size_t i = 0; i < pairs.size(); ++i)
        {
            if (pairs[i].second == *winnerIt)
            {
                sortedPairs.push_back(pairs[i]);
                break;
            }
        }
        ++winnerIt;
    }
    return sortedPairs;
}

template <typename Container>
Container insertLosers(const PairVector &sortedPairs, const Container &sortedWinners)
{
    if (sortedPairs.empty())
        return sortedWinners;

    Container sortedNumbers = sortedWinners;
    sortedNumbers.insert(sortedNumbers.begin(), sortedPairs[0].first);
    IntVector jacobsthal =
        generateJacobsthalSequence(static_cast<int>(sortedPairs.size()));
    IntVector insertionIndexes =
        generateInsertionIndexes(jacobsthal, static_cast<int>(sortedPairs.size()));
    for (size_t i = 0; i < insertionIndexes.size(); ++i)
    {
        int pairIndex = insertionIndexes[i];
        int loser = sortedPairs[pairIndex].first;
        int winner = sortedPairs[pairIndex].second;

        typename Container::iterator winnerPosition =
            std::find(sortedNumbers.begin(), sortedNumbers.end(), winner);
        typename Container::iterator insertionPosition =
            std::lower_bound(sortedNumbers.begin(), winnerPosition, loser);
        sortedNumbers.insert(insertionPosition, loser);
    }
    return sortedNumbers;
}

template <typename Container>
void insertLeftover(Container &sortedNumbers, int leftover)
{
    typename Container::iterator insertionPosition =
        std::lower_bound(sortedNumbers.begin(), sortedNumbers.end(), leftover);
    sortedNumbers.insert(insertionPosition, leftover);
}

template <typename Container>
Container fordJohnsonSort(const Container &sequence)
{
    if (sequence.size() <= 1)
        return sequence;
    if (sequence.size() == 2)
    {
        Container sorted = sequence;
        if (sorted[0] > sorted[1])
            std::swap(sorted[0], sorted[1]);
        return sorted;
    }
    int leftover = 0;
    bool hasLeftover = false;
    PairVector pairs = createPairs(sequence, leftover, hasLeftover);
    sortEachPair(pairs);
    Container winners = getWinners<Container>(pairs);
    Container sortedWinners = fordJohnsonSort(winners);
    PairVector sortedPairs = sortPairsByWinners(pairs, sortedWinners);
    Container sortedNumbers = insertLosers<Container>(sortedPairs, sortedWinners);

    if (hasLeftover)
        insertLeftover(sortedNumbers, leftover);
    return sortedNumbers;
}



int main(int argc, char **argv)
{
    std::vector<int> input;

    if (!parseArguments(argc, argv, input))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vectorSequence(input.begin(), input.end());
    std::deque<int> dequeSequence(input.begin(), input.end());

    std::cout << "Before: ";
    printSequence(input);

    std::vector<int> sortedVector = fordJohnsonSort(vectorSequence);
    std::deque<int> sortedDeque = fordJohnsonSort(dequeSequence);

    std::cout << "After vector: ";
    printSequence(sortedVector);
    std::cout << "After deque:  ";
    printSequence(sortedDeque);

    return 0;
}