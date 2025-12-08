#include <iostream>

void func(int ptr)
{  
    std::cout << "HELLO 2\n";
}
void func(int *ptr)
{
    std::cout << "HELLO 1\n";
}

int main()
{
    // int ptr = NULL;
    func(nullptr);
    // func(NULL);
}