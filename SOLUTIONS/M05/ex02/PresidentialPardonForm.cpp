#include "PresidentialPardonForm.hpp"

// CANONICAL FUNCTIONS
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardon",25,5), target("default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target): AForm(name,72,45), target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), target(other.target) {};

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (&other != this)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
	return *this;
}

// METHODS
void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!checkSign())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    std::cout << target 
              << " has been pardoned by Zaphod Beeblebrox." 
              << std::endl;
}