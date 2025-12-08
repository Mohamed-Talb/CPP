#include <iostream>

class test
{
    public:
    int a;
    int *b;
    test()
    {
        a  = 10;
        b = new int;
        *b = 16;
    }
    ~test()
    {
        std::cout << "destructor\n";
    }
};

int main()
{
    test T;
    std::cout << *(T.b) << std::endl;
}
