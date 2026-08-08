#include "Form.hpp"

// CANONICAL FORM FUNCTIONS
Form::Form(): name("default"),isSigned(false),gradeToSign(150),gradeToExecute(150){}

Form::Form(const Form &F): name(F.name),isSigned(F.isSigned),gradeToSign(F.gradeToSign),gradeToExecute(F.gradeToExecute){}

Form::~Form() {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : name(name),isSigned(false), gradeToSign(gradeToSign),gradeToExecute(gradeToExecute)
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw GradeTooHighException();
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw GradeTooLowException();
}

Form &Form::operator=(const Form &other)
{
	if (&other != this)
        this->isSigned = other.isSigned;
	return *this;
}

// METHODS
std::string Form::getName() const {return name;}
bool Form::checkSign() const { return isSigned;}
int Form::getGradeToSign() const {return gradeToSign;}
int Form::getGradeToExecute() const {return gradeToExecute;}
void Form::beSigned(Bureaucrat &B)
{
    if (isSigned)
        throw Form::AlreadySignedException();
    if (B.getGrade() > gradeToSign)
        throw Bureaucrat::GradeTooLowException();
    isSigned = true;
}

// // EXCEPTIONS
const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Grade too hight.";
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Grade too low.";
}
const char *Form::AlreadySignedException::what() const throw()
{
	return "Form Already signed.";
}

// OPERATORS
std::ostream &operator<<(std::ostream &out, const Form &F)
{
	std::string sign = "Not Signed"; 
	if (F.checkSign())
		sign = "Signed";
    out << F.getName() 
        << " Form, grade to sign " << F.getGradeToSign()
        << ", grade to execute " << F.getGradeToExecute()
        << ", " << sign;
    return out;
}