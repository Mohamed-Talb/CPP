#include <iostream>
#include <fstream>

// void replace(std::string content, std::string s1, std::string s2)
// {
//     for
// }

int main(int ac, char **av)
{
    std::string s1;
    std::string s2;
    std::string file = av[1];
    std::string content;
    std::string Buffer;
    std::ifstream intfile(file);
    while (std::getline(intfile, Buffer))
    {
        if(!intfile.eof())
            Buffer += '\n';
        content += Buffer;
    }
    std::cout << content << std::endl;
}