#include "Identify.hpp"
int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < 10; ++i) 
	{
        Base* obj = generate();
        std::cout << "Pointer identify: ";
        identify(obj);
        std::cout << "Reference identify: ";
        identify(*obj);
        delete obj;
        std::cout << "----------------" << std::endl;
    }

    return 0;
}