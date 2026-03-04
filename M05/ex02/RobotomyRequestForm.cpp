#include "RobotomyRequestForm.hpp"

// CANONICAL FUNCTIONS
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequest",72,45), target("default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target): AForm(name,72,45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), target(other.target) {};

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (&other != this)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
	return *this;
}

// METHODS
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!checkSign())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bzzzzzz... drilling noises..." << std::endl;
    std::srand(std::time(NULL));
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "." << std::endl;
}
