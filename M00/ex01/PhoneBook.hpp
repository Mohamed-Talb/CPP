#include "Contact.hpp"

class PhoneBook
{
    Contact Contacts[8];
    int count;
    int index;
    public:
    PhoneBook();
    void Add(Contact Arg);
    void Search(std::string Index);
    int BookSize();
};