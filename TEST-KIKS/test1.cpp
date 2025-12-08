#include <iostream>

class Test
{
    int a;
    int b;

public:
    Test(): b(initB()), a(initA())
    {
        std::cout << "Constructor body\n";
    }
    static int initA()
    {
        std::cout << "A\n";
        return 1;
    }
    static int initB()
    {
        std::cout << "B\n";
        return 2;
    }
};

int main()
{
    Test t;
    return 0;
}
