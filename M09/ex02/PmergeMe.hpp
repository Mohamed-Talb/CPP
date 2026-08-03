#ifndef PMERGEME_HPP
#define PMERGEME_HPP


typedef std::vector<int> IntVector;
typedef std::deque<int> IntDeque;
typedef std::pair<int, int> Pair;
typedef std::vector<Pair> PairVector;



#include <cerrno>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <vector>




typedef std::vector<int> IntVector;
typedef std::deque<int> IntDeque;
typedef std::pair<int, int> Pair;
typedef std::vector<Pair> PairVector;

/* JACOBSTHAL */

IntVector generateJacobsthalSequence(int pairCount);
IntVector generateInsertionIndexes(const IntVector &jacobsthal, int pairCount);

/* VECTOR FORD-JOHNSON HELPERS */

PairVector createPairs(const IntVector &sequence, int &leftover, bool &hasLeftover);
void sortEachPair(PairVector &pairs);
IntVector getWinners(const PairVector &pairs);
PairVector sortPairsByWinners(const PairVector &pairs, const IntVector &sortedWinners);
IntVector insertLosers(const PairVector &sortedPairs, const IntVector &sortedWinners);
void insertLeftover(IntVector &sortedNumbers, int leftover);

/* SORTING */

IntVector fordJohnsonVector(const IntVector &sequence);
IntDeque fordJohnsonDeque(const IntDeque &sequence);

/* PARSING */

bool parseArguments(int argc, char **argv, IntVector &numbers);

#endif