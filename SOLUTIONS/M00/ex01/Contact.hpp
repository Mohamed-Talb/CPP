#include <iostream>
#include <iomanip>

class Contact
{
    int index;
    std::string	firstName;
    std::string	lastName;
    std::string	nickName;
    std::string	phoneNumber;
    std::string	darkestSecret;
    public:
        void    ContactInfos();
        void	ContactSummary();
        void	setIndex(int Index);
        bool	setLastName(std::string Arg);
        bool	setNickName(std::string Arg);
        bool	setFirstName(std::string Arg);
        bool	setPhoneNumber(std::string Arg);
        bool	setDarkestSecret(std::string Arg);
        std::string getValueOf(std::string Arg) const;

};