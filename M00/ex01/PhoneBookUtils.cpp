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
    Arg.setIndex(index);
    Contacts[index] = Arg;
    index++;
    if (count < 9)
        count++;
    return ;
}

void PhoneBook::BookSummary()
{
    for (int i = 0; i < count; i++)
        Contacts[i].ContactSummary();
}

void PhoneBook::Search(std::string Index)
{
    int IIndex;
    Contact contact;

    IIndex = Index[0] - '0';
    if (Index.length() != 1 ||  IIndex < 1 || IIndex > count)
    {
        std::cout << "BAD INDEX, TRY AGAIN!!!" << std::endl;
        return ;
    }
    Contacts[IIndex - 1].ContactInfos();
    std::cout << std::endl;
    return ;
}

int PhoneBook::BookSize()
{
    return count;
}