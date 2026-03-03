#include "Bureaucrat.hpp"
#include "AForm.hpp"

// CANONICAL FORM FUNCTIONS
Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &B) : name(B.name), grade(B.grade){}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (&other != this)
		this->grade =  other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

// METHODS
int Bureaucrat::getGrade() const {return grade;}
std::string Bureaucrat::getName() const {return name;}


void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}
void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::signForm(Form &F)
{
    try
    {
        F.beSigned(*this);
        std::cout << name << " signed " << F.getName() << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << name << " couldn't sign " << F.getName() << " because " << error.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        F.execute(*this);
        std::cout << name << " executed " << F.getName() << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << name << " couldn't execute " << F.getName() << " because " << error.what() << std::endl;
    }
}

// EXCEPTIONS
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bereaucrat Grade too hight.";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bereaucrat Grade too low.";
}

// OPERATORS
std::ostream &operator<<(std::ostream &out, const Bureaucrat &B)
{
	out << B.getName() << ", bureaucrat grade " << B.getGrade();
	return out;
}