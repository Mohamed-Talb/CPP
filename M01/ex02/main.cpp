#include <iostream>

int main()
{
    std::string String = "HI THIS IS BRAIN";
    std::string *stringPTR = &String;
    std::string &stringREF = String;

    std::cout  << &String << std::endl; 
    std::cout  << stringPTR << std::endl; 
    std::cout  << &stringREF << std::endl; 

    std::cout  << String << std::endl; 
    std::cout  << *stringPTR << std::endl;
    std::cout  << stringREF << std::endl; 
}