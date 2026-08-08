#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <set>
#include <deque>
#include <cerrno>
#include <string>
#include <vector>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <utility>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>

typedef std::vector<int> IntVector;
typedef std::deque<int> IntDeque;
typedef std::pair<int, int> Pair;
typedef std::vector<Pair> PairVector;

IntVector fordJohnson(const IntVector &sequence);
IntDeque fordJohnson(const IntDeque &sequence);
#endif