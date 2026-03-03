#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	std::string target;
    public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &F);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		virtual void execute(Bureaucrat const &executor) const;
};
