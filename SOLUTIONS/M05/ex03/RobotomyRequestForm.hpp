#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime> 

class RobotomyRequestForm : public AForm
{
	std::string target;
    public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name, std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &F);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
		static AForm *createForm(std::string name, std::string target);
		virtual void execute(Bureaucrat const &executor) const;
};

#endif