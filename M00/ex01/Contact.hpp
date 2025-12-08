#include <iostream>
#include <cctype>
#include <iomanip>

class Contact
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    public:
    bool setFirstName(std::string Arg);
    bool setLastName(std::string Arg);
    bool setNickName(std::string Arg);
    bool setPhoneNumber(std::string Arg);
    bool setDarkestSecret(std::string Arg);
    std::string getElement(std::string Arg) const;
};