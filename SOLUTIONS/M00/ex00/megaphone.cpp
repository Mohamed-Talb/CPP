#include <iostream> 
#include <string>

int main(int ac, char *av[])
{
    int i;
    std::string str;
    std::string temp;

    i = 1;
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    while(i < ac)
    {
        temp = av[i];
        for (int j = 0; temp[j]; j++)
            str += std::toupper(temp[j]);
		i++;
    }
	std::cout << str << std::endl;
    return (0);
}


