#include "PhoneBook.hpp"

void FetchData(const std::string Option, Contact &contact)
{
    std::string Element;
    while (true)
    {
        std::cout << "Enter " << Option << ": ";
        if (!getline(std::cin, Element))
        {
            std::cout << std::endl;
            break;
        }
        bool success = false;
        if (Option == "First Name")
            success = contact.setFirstName(Element);
        else if (Option == "Last Name")
            success = contact.setLastName(Element);
        else if (Option == "Nickname")
            success = contact.setNickName(Element);
        else if (Option == "Phone Number")
            success = contact.setPhoneNumber(Element);
        else if (Option == "Darkest Secret")
            success = contact.setDarkestSecret(Element);
        if (success)
            break ;
    }
}


int main()
{
    std::string Options[] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
    std::string choise;
    std::string Index;
    Contact NewContact;
    PhoneBook Book;
    while(1)
    {
        std::cout << "ENTER ACTION [ADD-SEARCH-EXIT]: ";
        if (!getline(std::cin, choise)) // ??????????????
        {
            std::cout << std::endl; // ?????????????
            return 1;
        }
        if (choise.empty())
            continue;
        else if (choise == "ADD")
        {
            for(int i = 0; i < 5; i++)
            {
                FetchData(Options[i], NewContact);
            }
            Book.Add(NewContact);
            std::cout << "CONTACT SAVED SUCCESSFULLY!!\n";
            continue;
        }
        else if (choise == "SEARCH")
        {
            if (Book.BookSize() == 0)
                std::cout << "YOU CANNOT SEARCH, PHONE BOOK EMPTY!!\n";
            else
            {
                std::cout << "CONTACT INDEX (1-" << Book.BookSize() <<"):";
                if (!getline(std::cin, choise)) // ??????????????
                {
                    std::cout << std::endl; // ?????????????
                    return 1;
                }
                if (choise.empty())
                    continue;
                Book.Search(Index);            
            }
        }
    }
}