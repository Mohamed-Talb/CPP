#include <Bureaucrat.hpp>
Bureaucrat::Bureaucrat()
{
	grade = 0;	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : grade(grade)
{
	if (grade < 1)
        throw GradeTooHighException("Grade too high!");
    if (grade > 150)
        throw GradeTooLowException("Grade too low!");
    this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &B) : name(B.name), grade(B.grade){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (&other != this)
		this->grade =  other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}
std::string Bureaucrat::getName() const {return name;}
int Bureaucrat::getGrade() const {return grade;}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return message.c_str();
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return message.c_str();
}
