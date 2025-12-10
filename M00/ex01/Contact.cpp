#include "Contact.hpp"

bool Contact::setFirstName(std::string Arg)
{
    if (Arg.empty())
    {
        std::cout << "INVALID: First Name is empty\n";
        return (false);
    }
    firstName = Arg;
    return (true);
}

bool Contact::setLastName(std::string Arg)
{
    if (Arg.empty())
    {
        std::cout << "INVALID: Last Name is empty\n";
        return (false);
    }
    lastName = Arg;
    return (true);
}

bool Contact::setNickName(std::string Arg)
{
    if (Arg.empty())
    {
        std::cout << "INVALID: Nickname is empty\n";
        return (false);
    }
    nickName = Arg;
    return (true);
}

bool Contact::setPhoneNumber(std::string Arg)
{
    if (Arg.empty())
    {
        std::cout << "INVALID: Phone number is empty\n";
        return (false);
    }
    for (size_t i = 0; i < Arg.length(); i++)
    {
        if (!std::isdigit(Arg[i]))
        {
            std::cout << "INVALID: Phone number contains non-digit characters\n";
            return (false);
        }
    }
    phoneNumber = Arg;
    return (true);
}

bool Contact::setDarkestSecret(std::string Arg)
{
    if (Arg.empty())
    {
        std::cout << "INVALID: Darkest Secret is empty\n";
        return (false);
    }
    darkestSecret = Arg;
    return (true);
}

void Contact::ContactInfos()
{
    std::cout << std::endl << "CONTACT INFORMATIONS: " << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

std::string Contact::getValueOf(std::string Arg) const 
{
    if (Arg == "FirstName")
        return (firstName);
    else if (Arg == "LastName")
        return (lastName);
    else if (Arg == "NickName")
        return (nickName);
    else if (Arg == "DarkestSecret")
        return (darkestSecret);
    else if (Arg == "PhoneNumber")
        return (phoneNumber);
    else
        return ("");
}

void Contact::setIndex(int Index)
{
    index = Index + 1;
}

void Contact::ContactSummary()
{
    std::string CInfos[5];
    std::string Value;

    CInfos[0] = firstName;
    CInfos[1] = lastName;
    CInfos[2] = nickName;
    CInfos[3] = phoneNumber;
    CInfos[4] = darkestSecret;
    std::cout << std::setw(10) << index << '|';
    for (int i = 0; i < 3; i++)
    {
        Value = CInfos[i];
        if (Value.length() > 9)
            Value = Value.substr(0,9) + '.';
        std::cout << std::setw(10) << Value;
        if (i != 2)
            std::cout << "|";
    }
    std::cout << std::endl;
}