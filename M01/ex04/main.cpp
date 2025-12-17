#include <iostream>
#include <fstream>

// std::string replace(std::string content, const std::string& s1, const std::string& s2)
// {
//     std::string newcontent;
//     size_t index;
//     while ((index = content.find(s1)) != std::string::npos)
//     {
//         newcontent += content.substr(0, index);
//         newcontent += s2;
//         content = content.substr(index + s1.length());
//     }
//     newcontent += content;
//     return newcontent;
// }

std::string replace(std::string content, const std::string& s1, const std::string& s2)
{
    size_t index;
    size_t s1len = s1.length();
    while ((index = content.find(s1)) != std::string::npos)
    {
        content.erase(index, s1len);
        content.insert(index, s2);
    }
    return content;
}


int main(int ac, char **av)
{
    std::string s1 = av[2];
    std::string s2 = av[3];
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
    intfile.close();
    std::ofstream outfile("hello.txt");
    std::string nec = replace(content, s1, s2);
    // outfile << replace(content, s1, s2);
    outfile << nec;
    std::cout << nec;
}