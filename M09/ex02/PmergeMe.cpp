#include "PmergeMe.hpp"

typedef std::deque<int> IntDeque;
typedef std::pair<int, int> Pair;
typedef std::vector<int> IntVector;
typedef std::vector<Pair> PairVector;

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
    for (std::size_t i = 3; i < jacobsthal.size(); ++i)
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

PairVector createPairs(const IntVector &sequence, int &leftover, bool &hasLeftover)
{
    PairVector pairs;
    hasLeftover = sequence.size() % 2 != 0;
    std::size_t pairedSize = sequence.size();
    if (hasLeftover)
    {
        leftover = sequence.back();
        --pairedSize;
    }
    for (std::size_t i = 0; i < pairedSize; i += 2)
        pairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));

    return pairs;
}

void sortEachPair(PairVector &pairs)
{
    for (std::size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

IntVector getWinners(const PairVector &pairs)
{
    IntVector winners;
    for (std::size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].second);

    return winners;
}

PairVector sortPairsByWinners(const PairVector &pairs, const IntVector &sortedWinners)
{
    PairVector sortedPairs;

    for (std::size_t i = 0; i < sortedWinners.size(); ++i)
    {
        for (std::size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].second == sortedWinners[i])
            {
                sortedPairs.push_back(pairs[j]);
                break;
            }
        }
    }
    return sortedPairs;
}

IntVector insertLosers(const PairVector &sortedPairs, const IntVector &sortedWinners)
{
    if (sortedPairs.empty())
        return sortedWinners;

    IntVector sortedNumbers = sortedWinners;
    sortedNumbers.insert(sortedNumbers.begin(), sortedPairs[0].first);
    IntVector jacobsthal = generateJacobsthalSequence(static_cast<int>(sortedPairs.size()));
    IntVector insertionIndexes = generateInsertionIndexes(jacobsthal, static_cast<int>(sortedPairs.size()));
    for (std::size_t i = 0; i < insertionIndexes.size(); ++i)
    {
        int pairIndex = insertionIndexes[i];
        int loser = sortedPairs[pairIndex].first;
        int winner = sortedPairs[pairIndex].second;
        IntVector::iterator winnerPosition =
            std::find(sortedNumbers.begin(), sortedNumbers.end(), winner);
        IntVector::iterator insertionPosition =
            std::lower_bound(sortedNumbers.begin(), winnerPosition, loser);
        sortedNumbers.insert(insertionPosition, loser);
    }

    return sortedNumbers;
}

void insertLeftover(IntVector &sortedNumbers, int leftover)
{
    IntVector::iterator insertionPosition =
        std::lower_bound(sortedNumbers.begin(), sortedNumbers.end(), leftover);
    sortedNumbers.insert(insertionPosition, leftover);
}

IntVector fordJohnson(const IntVector &sequence)
{
    if (sequence.size() <= 1)
        return sequence;
    if (sequence.size() == 2)
    {
        IntVector sorted = sequence;
        if (sorted[0] > sorted[1])
            std::swap(sorted[0], sorted[1]);
        return sorted;
    }
    int leftover = 0;
    bool hasLeftover = false;
    PairVector pairs = createPairs(sequence, leftover, hasLeftover);
    sortEachPair(pairs);
    IntVector winners = getWinners(pairs);
    IntVector sortedWinners = fordJohnson(winners);
    PairVector sortedPairs = sortPairsByWinners(pairs, sortedWinners);
    IntVector sortedNumbers = insertLosers(sortedPairs, sortedWinners);
    if (hasLeftover)
        insertLeftover(sortedNumbers, leftover);
    return sortedNumbers;
}

IntDeque fordJohnson(const IntDeque &sequence)
{
    IntVector vectorSequence(sequence.begin(), sequence.end());
    IntVector sortedVector = fordJohnson(vectorSequence);
    IntDeque sortedDeque(sortedVector.begin(), sortedVector.end());
    return sortedDeque;
}