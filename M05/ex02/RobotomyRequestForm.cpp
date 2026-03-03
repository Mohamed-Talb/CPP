#include "RobotomyRequestForm.hpp"

// CANONICAL FUNCTIONS
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm",72,45), target(default){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm",72,45), target(target){}

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
    if (!this->getIsSigned())
        throw Form::FormNotSignedException();

    if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    std::cout << "Bzzzzzz... drilling noises..." << std::endl;
    std::srand(std::time(nullptr));
    if (std::rand() % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << this->getTarget() << "." << std::endl;
}
