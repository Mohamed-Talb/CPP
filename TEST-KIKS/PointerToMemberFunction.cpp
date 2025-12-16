#include <iostream>
using namespace std;

int Globalefunc(int numb)
{
    return numb;
}

class Person
{
    public:
    void speak(int volume, int name)
    {
        cout << "hello I am  " << name << endl;
    }
    int getAge() const
    {
        cout << "Age" << endl;
        return 2;
    }
    static int Square(int x)
    {
        return (x * x);
    }
};

int main()
{
    void (Person::*ptrSpeak)(int, int) = &Person::speak; 
    int (Person::*ptrage)()const = &Person::getAge;
    int (*ptrSquare)(int) = &Person::Square;
    int (*Globalefunc)(int) = Globalefunc;

    Person p;
    (p.*ptrSpeak)(10, 20);
    int age1 = (p.*ptrage)();

    Person *pp = &p;
    (pp->*ptrSpeak)(20,25);
    int age2 = (pp->*ptrage)();
}