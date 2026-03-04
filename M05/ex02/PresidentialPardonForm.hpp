#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	std::string target;
    public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name, std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &F);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		virtual void execute(Bureaucrat const &executor) const;
};