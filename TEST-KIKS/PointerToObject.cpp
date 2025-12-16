#include <iostream>
using namespace std;

class Person
{
    public:
        int age;
        void speak()
        {
            cout << "Hello\n"; 
        }
};

int main()
{
    Person p;
    p.age = 20;
    cout << p.age << endl;
    Person *ptr = &p;
    ptr->age = 25;
    cout << p.age << endl;
    cout << ptr->age << endl;
    ptr->speak();
}