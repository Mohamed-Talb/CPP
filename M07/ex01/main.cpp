#include "iter.hpp"

void printInt(int& n)
{
    std::cout << n << " ";
}

void incrementInt(int& n)
{
    n += 1;
}

void printConstInt(const int& n)
{
    std::cout << n << " ";
}

int main()
{
	    // ----- Test 1: int array -----
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original int array: ";
    iter(arr, len, printInt);
    std::cout << std::endl;

    iter(arr, len, incrementInt);

    std::cout << "Incremented int array: ";
    iter(arr, len, printInt);
    std::cout << std::endl;

    // ----- Test 2: const int array -----
    const int cArr[] = {10, 20, 30};
    size_t cLen = sizeof(cArr) / sizeof(cArr[0]);

    std::cout << "Const int array: ";
    iter(cArr, cLen, printConstInt);
    std::cout << std::endl;
}