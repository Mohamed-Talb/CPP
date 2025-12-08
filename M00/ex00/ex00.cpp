#include <iostream> 
#include <string>

int main(int ac, char *av[])
{
    int i;
    std::string str;

    i = 1;
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return (1);
    }
    while(i < ac)
    {
        str = av[i];
        for (int j = 0; str[j]; j++)
        {
            str = str[j];
            std::cout << (char)std::toupper(str[j]);
        }
		i++;
    }
	std::cout << std::endl;
}


