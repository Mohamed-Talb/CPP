#include <iostream>
using namespace std ;

// int main()
// {
//     int a = 5;
//     int &ref = a;
//     // int &ref = 33; // Error 
//     const int &ref2 = 10; /// fix it by adding const
//     cout << ref2 << endl;

//     const int &ref3 = a;
//     cout << ref3 << endl;

//     ref = 20;
//     cout << ref << endl << a << endl;

//     int x = ref + 5;
//     cout << x  << endl;
// }


// int main()
// {
//    int x = 5;
//    int y = 6;
//    int *ptr = &x;
//    int *&refptr = ptr;
   
//    *refptr = 20;
//    refptr = &y;
// }

class Person
{
    public:
        int age;
        void func1(int &x)
        {
            x += 1;
        }
        void func2(const int &x)
        {
            // x += 1; // Error
            cout << x << endl;
        }
};

int &getValue()
{
    static int x = 50;
    return x;
}


// int main()
// {
//     Person p;
//     int a = 1;
//     int &ref = a;

//     p.func1(ref);
//     // cout << ref << endl;
//     p.func2(ref);
//     ref = getValue();
//     ref = 100;
//     cout << ref << endl;
// }

// int add(int x, int y)
// {
//     return x + y;
// }

// int (&refAdd)(int, int) = add;

// int main()
// {
    
// }
