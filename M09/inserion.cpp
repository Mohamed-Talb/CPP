#include <array>
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

std::vector<int> Numbers;
typedef std::vector<std::pair<int, int> > Pairs_t;


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


static void printVector(const std::vector<int> &sequence)
{
    for (std::vector<int>::size_type i = 0; i < sequence.size(); ++i)
    {
        std::cout << sequence[i];

        if (i + 1 < sequence.size())
            std::cout << " ";
    }

    std::cout << std::endl;
}

std::vector<int> AC7_generateJcob(int pairsNumber)
{
    std::vector<int> JAcob;
    JAcob.push_back(0);
    JAcob.push_back(1);
    int n = 2;
    int Jn = 0;
    while (Jn <= pairsNumber)
    {
        Jn = JAcob[n - 1] + (2 * JAcob[n - 2]);
        JAcob.push_back(Jn);
        n++;
    }
    return JAcob;
}

std::vector<int> AC8_indexesWithJacob(std::vector<int> JAcobSeq)
{
    std::vector<int > fullSeq;
    for (int i = 2; i < JAcobSeq.size(); i++)
    {
        fullSeq.push_back(JAcobSeq[i]);
        if (JAcobSeq[i - 1] != JAcobSeq[i] - 1)
        {
            for (int j = JAcobSeq[i] - 1; j > JAcobSeq[i - 1]; j--)
                fullSeq.push_back(j);
        }
    }
    printVector(fullSeq);
    for (int i = 0; i < fullSeq.size(); i++)
    {
        fullSeq[i] -= 1;
    }
    return fullSeq;
}


void AC6_insertLeft(std::vector<int>  &SortedNumbers, int &left)
{
    std::vector<int>::iterator isPos = std::lower_bound(SortedNumbers.begin(), SortedNumbers.end(), left);
    SortedNumbers.insert(isPos, left);
    // for (int i = 0; i < SortedNumbers.size(); i++)
    // {
    //     if ()
    // }

}

std::vector<int>  AC5_insertLoosers(Pairs_t &sortedPairs, std::vector<int> &sortedWinners, std::vector<int> JacobIndexes)
{
    if (sortedPairs.empty())
        return sortedWinners;
    std::vector<int> sortedNumbers = sortedWinners;
    sortedNumbers.insert(sortedNumbers.begin(), sortedPairs[0].first);
    for (int i = 1; i < JacobIndexes.size(); i++)
    {
        std::pair<int, int> currPair = sortedPairs[JacobIndexes[i]];
        int looser = currPair.first;
        int winner = currPair.second;
        std::vector<int>::iterator winnerPos = find(sortedNumbers.begin(), sortedNumbers.end(), winner);
        std::vector<int>::iterator insertionPos = std::lower_bound(sortedNumbers.begin(), winnerPos, looser);
        sortedNumbers.insert(insertionPos, looser);
    }
    return sortedNumbers;
}

Pairs_t AC4_SortedPairsByWinners(Pairs_t &Pairs, std::vector<int> &sortedWinners)
{
    Pairs_t sortedPairs;
    for(int i = 0; i < sortedWinners.size(); i++)
    {
        for(int j = 0; j < Pairs.size(); j++)
        {
            if (Pairs[j].second == sortedWinners[i])
            {
                sortedPairs.push_back(Pairs[j]);
                break;
            }
        }
    }
    return sortedPairs;
}

void AC3_GetWinners(Pairs_t &Pairs, std::vector<int> &Winners)
{
    for(int i = 0; i < Pairs.size(); i++)
    {
        Winners.push_back(Pairs[i].second);
    }
}

void AC2_SortEachPair(Pairs_t &Pairs)
{
    for (int i = 0; i < Pairs.size(); i++)
    {
        if (Pairs[i].first > Pairs[i].second)
            std::swap(Pairs[i].first, Pairs[i].second);
    }
}

Pairs_t AC1_CreatePairs(std::vector<int> Sequence, int &leftOver)
{
    Pairs_t pairs;
    if (Sequence.size() % 2 != 0)
    {
        leftOver = Sequence.back();
        Sequence.pop_back();
    }
    for(int i = 0; i < Sequence.size(); i+=2)
    {
        pairs.push_back(std::make_pair(Sequence[i], Sequence[i + 1]));
    }
    return pairs;
}


std::vector<int> FordJhonson(std::vector<int> Sequence)
{
    if (Sequence.size() == 1)
    {
        return Sequence;
    }
    int leftOver = -1;
    std::vector<int> Winners;
    Pairs_t Pairs = AC1_CreatePairs(Sequence, leftOver);
    AC2_SortEachPair(Pairs);
    AC3_GetWinners(Pairs, Winners);
    std::vector<int> sortedWinners = FordJhonson(Winners);
    Pairs_t sortedPairs = AC4_SortedPairsByWinners(Pairs, sortedWinners);
    std::vector<int> JacobSeq = AC7_generateJcob(sortedWinners.size());
    std::vector<int> Jacobindexs = AC8_indexesWithJacob(JacobSeq);
    std::vector<int> sortedNumbers = AC5_insertLoosers(sortedPairs, sortedWinners, Jacobindexs);
    if (leftOver != -1)
        AC6_insertLeft(sortedNumbers, leftOver);
    return sortedNumbers;
}


#include <iostream>
#include <vector>


int main()
{
    std::vector<int> sequence;

    sequence.push_back(10);
    sequence.push_back(3);
    sequence.push_back(7);
    sequence.push_back(2);
    sequence.push_back(8);

    std::cout << "Before: ";
    printVector(sequence);

    std::vector<int> sortedSequence = FordJhonson(sequence);

    std::cout << "After:  ";
    printVector(sortedSequence);
    
    // std::vector<int> JacobSeq = AC7_generateJcob(7);
    // printVector(JacobSeq);
    // std::vector<int > indexes = AC8_indexesWithJacob(JacobSeq);
    // printVector(indexes);
    return 0;
}