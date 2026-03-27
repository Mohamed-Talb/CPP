#include "easyfind.hpp"

template <typename T>
void easyfind(T conatainer, int arg)
{
	typename T::iterator result = std::find(conatainer.begin(), conatainer.end(), arg);
	if (result != conatainer.end()) 
		std::cout << "Value " << arg << " found at index: " 
		<< std::distance(conatainer.begin(), result) << std::endl;
	else 
		throw std::invalid_argument("EASYFIND: Value not found");
}