#include <iostream>
#include <string>

class Person
{
    std::string name;
    int age;
    public:
        Person(std::string n, int a)
        {
            name = n;
            age = a;
        }
        std::string getName() const
        {
            return name;
        }
        std::string UpdateName(std::string n)
        {
                name = n; // Allowed
        }
        // std::string UpdateName() const
        // {
            //     name = "mohamed"; // not allowed
        // }
};

int main()
{
    const Person p("Alice", 20);  // CONST OBJECT
    std::cout << p.getName() << "\\n";  // allowed
    return 0;
}
