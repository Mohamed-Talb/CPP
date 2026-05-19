#include <array>
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

std::vector<int> randomArr(size_t size)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0, 100);
    std::vector<int> rVector;
    for (size_t i = 0; i < size; i++)
    {
        rVector.push_back(dist(gen));
    }
    return rVector;
}



int main()
{
    std::vector<int> RV = randomArr(10);
    for (int x : RV)
        std::cout << x << " ";
    std::cout << std::endl;
    int tmp;
    // INSERTION SORT 

    for (size_t i = 1; i < RV.size(); i++)
    {
        for (size_t j = i; j > 0; j--)
        {
            if (RV[j] < RV[j - 1])
                std::swap(RV[j], RV[j - 1]);
            else
                break;
        }
    }
    for (int x : RV)
        std::cout << x << " ";
}