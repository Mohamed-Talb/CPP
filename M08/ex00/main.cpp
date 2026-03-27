#include "easyfind.hpp"

template <typename C>
void printContainer(C container)
{
	typename C::iterator it = container.begin();
	while (it != container.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}

int main()
{
    std::vector<int> Vect; 
    std::list <int> Lst;

	Vect.push_back(21);
	Vect.push_back(1337);
	Vect.push_back(42);

	Lst.push_back(1);
	Lst.push_back(2);
	Lst.push_front(3);

	printContainer(Vect);
	printContainer(Lst);
}