#include "Serializer.hpp"

int main()
{
	Data data = {"mohamed",20, 12.88};
	std::cout << data.name << std::endl << data.age << std::endl << data.amount << std::endl;
	Data *dPtr = &data;
	uintptr_t addr = Serializer::serialize(dPtr);
	Data *newDataPtr = Serializer::deserialize(addr);
	std::cout << addr << std::endl;
	std::cout << newDataPtr->name << std::endl << newDataPtr->age << std::endl << newDataPtr->amount << std::endl;
}
