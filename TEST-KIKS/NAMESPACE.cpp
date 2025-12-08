#include <iostream>
#include <string>
#include <fstream>

// namespace Tools
// {
//     // int number = 10;
//     void show(int number)
//     {
//         std:: cout << "Number = " << number << std::endl;
//     }
//     int add(int n1, int n2)
//     {
//         return (n1 + n2);
//     }
//     namespace privet
//     {
//         void SayHello()
//         {
//             std::cout << "HELLO MY FRIEND." << std::endl;
//         }
//     }
// }

// using namespace Tools;

// int main()
// {
//     int a = 10;
//     int b = 11;;
//     show(a);
//     show(b);
//     int result = Tools::add(a, b);
//     std::cout << "THE RESULT IS: " << std::endl << result << std::endl;
//     Tools::privet::SayHello();
//     namespace Privet = Tools::privet;
// }

int main(void)
{
    // int i = 0;
    // while (i < 25)
    // {
    //     std::cout << "hello 111 world!" << "\n";
    //     // std::cout << "hello 444 world!" << "\n";
    //     // std::cout << "hello 888 world!" << "\n";
    //     i++;
    // }
    std::string name;
    int age;
    int age2;
    std::cout << "HELLO MY FRIEND." << std::endl;
    // std::cout << "ENTER YOUR NAME: ";
    // std::cin >> name;
    // std::cout << "ENTER YOUR AGE: ";
    // std::cin >> age;
    // std::cout << name << std::endl;
    // std::cout << age << std::endl;
    // char ch;
    // std::string line;
    // std::cout << "Enter a character: ";
    // ch = std::cin.get();
    // std::cout << "you entered: " << ch << std::endl;
    // std::cin.ignore();
    // ch = std::cin.get();
    // std::cout << "you entered: " << ch << std::endl;
    // std::cin.ignore();
    // std::cout << "Enter a line of text: ";
    // std::getline(std::cin, line);
    // std::cout << "You entered: " << line << std::endl;
    std::ofstream outfile("test.txt");
    std::ofstream outfile2("test.txt");
    std::ofstream outfile3("test.txt");
    if (!outfile)
    {
        std::cout << "ERROR!" << std::endl; return 1;
    }
    std::cout;
    outfile << "HELLO from file" << std::endl;
    outfile.close();
    std::ifstream infile("test.txt");
    std::string line;
    std::getline(infile, line);
    std::cout << "read from file :" << line << std::endl;
    int i = 0;
    infile.close();
}