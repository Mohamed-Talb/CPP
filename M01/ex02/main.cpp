#include <iostream>

int main()
{
    std::string String = "HI THIS IS BRAIN";
    std::string *stringPtr = &String;
    std::string &stringRef = String;

    std::cout  << &String << std::endl; 
    std::cout  << stringPtr << std::endl; 
    std::cout  << &stringRef << std::endl; 

    std::cout  << String << std::endl; 
    std::cout  << *stringPtr << std::endl; //??????????????????
    std::cout  << stringRef << std::endl; 

    // std::string *strptr2 = &stringRef;
    // why we use reference 
    // ptr = address
    // *ptr 
}