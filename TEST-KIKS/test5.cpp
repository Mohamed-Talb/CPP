#include <iostream>

class Person
{
    std::string name;
    int age;
    public:
        void setData(std::string n, int a)
        {
            name = n;
            age = a;
        }
        std::string getName() const
        {
            return name;
        }
        int getAge() const
        {
            return age;
        }
        static int square(int x)
        {
            return x * x;
        }
        // void setAge(int a) const
        // {
        //     age = a;
        // }
};

class Person22
{
    std::string name;
    int age;
    public:
        void setData(std::string n, int a)
        {
            name = n;
            age = a;
        }
        std::string getName() const
        {
            return name;
        }
        int getAge() const
        {
            return age;
        }
};

int main()
{
    Person p1;
    std::cout << Person::square(5);
    p1.setData("alice", 20);
    std::cout << p1.getName() << "\n";  // allowed
    std::cout << p1.getAge() << "\n";   // allowed
    return 0;
}