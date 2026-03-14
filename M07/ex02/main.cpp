#include "Array.hpp"

void incrementArray(Array<int> &arr)
{
	std::cout << "Increment Array..." << std::endl;
	unsigned int len = arr.size();
	for (unsigned int i = 0; i < len; i++)
	{
		arr[i]++;
	}
}

void FillArray(Array<int> &arr)
{
	std::cout << "Fill Array..." << std::endl;
	unsigned int len = arr.size();
	for (unsigned int i = 0; i < len; i++)
	{
		arr[i] = i+1;
	}
}

template <typename T>
void printArray(Array<T> &arr)
{
	std::cout << "Array: " << std::endl;
	unsigned int len = arr.size();
	for (unsigned int i = 0; i < len; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}



int main()
{
	try
	{
		std::cout << "ARRAY I:" << std::endl;
		Array<int> arr1(5);
		printArray(arr1);
		FillArray(arr1);
		printArray(arr1);
		incrementArray(arr1);
		printArray(arr1);
		std::cout << "ARRAY II:" << std::endl;
		Array<int> arr2(arr1);
		printArray(arr2);
		incrementArray(arr2);
		printArray(arr2);
		printArray(arr1);
		std::cout << "ARRAY III:" << std::endl;
		Array<int> arr3;
		arr2 = arr3;
		arr3 = arr1;
		printArray(arr1);
		printArray(arr2);
		printArray(arr3);
		std::cout << arr2[8] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	// printArray(arr1);
	
}
