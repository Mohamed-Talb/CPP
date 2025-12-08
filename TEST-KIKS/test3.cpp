#include <iostream>

class Test
{
    int a;

public:
    void set(int a)
    {
        // this->a = a;
        a = a;
    }
    int get()
    {
        return(a);
    }
};
        
int main()
{
    Test t;
    t.set(4);
    std::cout << t.get();
    return 0;
}
