#include "Contact.hpp"

class PhoneBook
{
    Contact Contacts[8];
    int count;
    int index;
    public:
    PhoneBook();
    int BookSize();
    void BookSummary();
    void Add(Contact Arg);
    void Search(std::string Index);
};