#include "ShrubberyCreationForm.hpp"

// CANONICAL FUNCTIONS
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm",145,137), target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target): AForm(name,145,137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), target(other.target) {};

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (&other != this)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
	return *this;
}

// METHODS
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!checkSign())
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("File open failed");
}


AForm *ShrubberyCreationForm::createForm(std::string name, std::string target)
{
	return new ShrubberyCreationForm(name, target);
}