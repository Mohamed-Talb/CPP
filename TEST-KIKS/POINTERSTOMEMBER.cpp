#include <iostream>

using namespace std;

class Person
{
    public:
        int age = 0;
        double Hieght = 12.5;
};

int main()
{
    double Person::*ptrHieght = &Person::Hieght;
    Person p;
    int Person::*ptrAge = &Person::age;
    p.age = 20;
    int value = p.*ptrAge;
    double value2 = p.*ptrHieght;
    cout << value << endl;
    cout << value2 << endl;
    Person P2;
    value = P2.*ptrAge;
    Person *pp = &p;
    int value = pp->*ptrAge;
}