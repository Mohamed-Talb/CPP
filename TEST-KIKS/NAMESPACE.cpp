#include <iostream>
#include <string>
#include <fstream>

namespace Tools 
{
    int number = 10;
    void show()
    {
        std::cout << "number = " << number << std::endl;
    }
}


// USING KEY WORD
// using namespace std;
// using std::cout;
// using std::endl;


// nested NAME SPACE
namespace company
{
    namespace software
    {
        void info()
        {
            std::cout << "This is the software department." << std::endl;
        }
    }
}

namespace CS = company::software;


namespace {
    int secretNumber = 42;

    void showSecret() {
        std::cout << "The secret number is " << secretNumber << std::endl;
    }
}

namespace Library
{
    inline namespace version1
    {
        void print()
        {
            std::cout << "Lbrary version 1" << std::endl;
        }
    }
    namespace version2
    {
        void print()
        {
            std::cout << "Lbrary version 2" << std::endl;
        }
    }
}

int main()
{
    Tools::show();
    // cout << "hello" << endl;
    company::software::info();
    showSecret();
    Library::print();
}