#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    count = 0;
    index = 0;
}

void PhoneBook::Add(Contact Arg)
{
    if (index > 7)
        index = 0;
    Contacts[index] = Arg;
    index++;
    if (count < 9)
        count++;
    return ;
}

void PhoneBook::Search(std::string Index)
{
    int IIndex;
    std::string Elements[5];
    std::string Element;

    IIndex = Index[0] - '0';
    if (Index.length() != 1 || IIndex > count)
    {
        std::cout << "Contact Doesn't Exist\n" << std::endl;
        return ;
    }
    Elements[0] = Contacts[IIndex-1].getElement("FirstName");
    Elements[1] = Contacts[IIndex-1].getElement("LastName");
    Elements[3] = Contacts[IIndex-1].getElement("NickName");
    Elements[4] = Contacts[IIndex-1].getElement("PhoneNumber");
    Elements[5] = Contacts[IIndex-1].getElement("DarkestSecret");
    for (int i; i < 6; i++)
    {
        Element = Elements[i];
        if (Element.length() > 9)
            Element = Element.substr(0,9) + '.';
        std::cout << Element;
        if (i != 5)
            std::cout << "|";
    }
    std::cout << std::endl;
    return ;
}

int PhoneBook::BookSize()
{
    return count;
}