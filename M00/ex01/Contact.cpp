#include "Contact.hpp"

bool Contact::setFirstName(std::string Arg)
{
    if (Arg.empty())
    {
        std::cout << "INVALID: First Name is empty\n";
        return false;
    }
    firstName = Arg;
    return true;
}

bool Contact::setLastName(std::string Arg)
{
    if (Arg.empty())
    {
        std::cout << "INVALID: Last Name is empty\n";
        return false;
    }
    lastName = Arg;
    return true;
}

bool Contact::setNickName(std::string Arg)
{
    if (Arg.empty())
    {
        std::cout << "INVALID: Nickname is empty\n";
        return false;
    }
    nickName = Arg;
    return true;
}

bool Contact::setPhoneNumber(std::string Arg)
{
    if (Arg.empty())
    {
        std::cout << "INVALID: Phone number is empty\n";
        return false;
    }
    for (size_t i = 0; i < Arg.length(); i++)
    {
        if (!std::isdigit(Arg[i]))
        {
            std::cout << "INVALID: Phone number contains non-digit characters\n";
            return false;
        }
    }
    phoneNumber = Arg;
    return true;
}

bool Contact::setDarkestSecret(std::string Arg)
{
    if (Arg.empty())
    {
        std::cout << "INVALID: Darkest Secret is empty\n";
        return false;
    }
    darkestSecret = Arg;
    return true;
}

std::string Contact::getElement(std::string Arg) const 
{
    if (Arg == "FirstName")
        return this->firstName;
    else if (Arg == "LastName")
        return this->lastName;
    else if (Arg == "NickName")
        return this->nickName;
    else if (Arg == "DarkestSecret")
        return this->darkestSecret;
    else if (Arg == "PhoneNumber")
        return this->phoneNumber;
    else
        return "";
}