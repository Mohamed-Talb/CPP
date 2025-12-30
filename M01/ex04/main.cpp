#include <iostream>
#include <fstream>

std::string replace(std::string content, const std::string& s1, const std::string& s2)
{
    std::string newcontent;
    size_t index;
    while ((index = content.find(s1)) != std::string::npos)
    {
        newcontent += content.substr(0, index);
        newcontent += s2;
        content = content.substr(index + s1.length());
    }
    newcontent += content;
    return newcontent;
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "INVALID ARGUMENTS: Usage -> ./program file s1 s2" << std::endl;
        return 1;
    }
    std::string file = av[1];
    std::string s1   = av[2];
    std::string s2   = av[3];
    std::string content;
    std::string buffer;
    if (file.empty() || s1.empty())
    {
        std::cerr << "INVALID ARGUMENTS: file, s1, and s2 must not be empty" << std::endl;
        return 1;
    }
    std::ifstream infile(file.c_str());
    if (!infile.is_open())
    {
        std::cerr << "ERROR: Cannot open file '" << file << "' for reading" << std::endl;
        return 1;
    }
    while (std::getline(infile, buffer))
    {
        content += buffer;
        if (!infile.eof())
            content += '\n';
    }
    if (infile.bad())
    {
        std::cerr << "ERROR: Problem reading file '" << file << "'" << std::endl;
        infile.close();
        return 1;
    }
    infile.close();
    std::ofstream outfile((file + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cerr << "ERROR: Cannot open file '" << file << ".replace' for writing" << std::endl;
        return 1;
    }
    outfile << replace(content, s1, s2);
    if (outfile.fail())
    {
        std::cerr << "ERROR: Failed to write to '" << file << ".replace'" << std::endl;
        outfile.close();
        return 1;
    }
    outfile.close();
    std::cout << "Replacement completed successfully!" << std::endl;
    return 0;
}
