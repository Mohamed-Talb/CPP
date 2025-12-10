#include "PhoneBook.hpp"

int FetchData(const std::string Option, Contact &contact)
{
    std::string Value;
    while (true)
    {
        std::cout << "Enter " << Option << ": ";
        if (!getline(std::cin, Value))
        {
            std::cout << "Stream is in failed state (EOF or error)." << std::endl;
            return (0);
        }
        bool success = false;
        if (Option == "First Name")
            success = contact.setFirstName(Value);
        else if (Option == "Last Name")
            success = contact.setLastName(Value);
        else if (Option == "Nickname")
            success = contact.setNickName(Value);
        else if (Option == "Phone Number")
            success = contact.setPhoneNumber(Value);
        else if (Option == "Darkest Secret")
            success = contact.setDarkestSecret(Value);
        if (success)
            break ;
    }
    return (1);
}


int main()
{
    std::string Options[] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
    std::string Choise;
    std::string Index;
    Contact   NewContact;
    PhoneBook Book;
    while(1)
    {
        std::cout << "ENTER ACTION [ADD - SEARCH - EXIT]: ";
        if (!getline(std::cin, Choise))
        {
            std::cout << "Stream is in failed state (EOF or error)." << std::endl;
            return (1);
        }
        else if (Choise == "ADD")
        {
            for(int i = 0; i < 5; i++)
            {
                if (!FetchData(Options[i], NewContact))
                    return (1);
            }
            Book.Add(NewContact);
            std::cout << "CONTACT SAVED SUCCESSFULLY!!\n";
            continue;
        }
        else if (Choise == "SEARCH")
        {
            if (Book.BookSize() == 0)
                std::cout << "YOU CANNOT SEARCH, PHONE BOOK EMPTY!!" << std::endl;
            else
            {
                Book.BookSummary();
                std::cout << "CONTACT INDEX: ";
                if (!getline(std::cin, Index))
                {
                    std::cout << "Stream is in failed state (EOF or error)." << std::endl;
                    return (1);
                }
                Book.Search(Index);            
            }
        }
        else if (Choise == "EXIT")
            return (0);
        else
            std::cout << "BAD OPTIONS, TRY AGAIN!!!" << std::endl;
    }
}