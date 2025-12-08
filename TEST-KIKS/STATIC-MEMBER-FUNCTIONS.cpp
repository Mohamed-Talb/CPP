#include <iostream>

class MathTools
{
    int a;
    static int b;

    public:
    MathTools(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void GetAandB()
    {
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
    static int square(int x)
    {
        return x * x;
    }
    static void SetNewValues(int aa, int bb)
    {
        a = aa;
        b = bb;
    }
};




class A{
    static int a;

   
    public:
    A(int value)
    {
        a = value;
    }
    int geter()
    {
        return a;
    }
    static int sgeter()
    {
        this->a;
        return a;
    }
};

int main()
{
    A obj(5);

    std::cout << obj.geter();
}