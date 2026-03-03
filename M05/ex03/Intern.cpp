#include "Intern.hpp"

AForm *Intern::makeForm(std::string formName, std::string target)
{
	const std::string formsCatalogue[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*printer[3])(std::string, std::string) = {ShrubberyCreationForm::createForm, RobotomyRequestForm::createForm, PresidentialPardonForm::createForm};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formsCatalogue[i])
		{
			std::cout << "Intern creates " << formName << std::endl; 
			return printer[i](formName, target);
		}
	}
	throw std::invalid_argument("Form name not recognized");
}