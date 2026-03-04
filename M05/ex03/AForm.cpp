#include "AForm.hpp"

// CANONICAL AForm FUNCTIONS
AForm::AForm(): name("default"),isSigned(false),gradeToSign(150),gradeToExecute(150){}

AForm::AForm(const AForm &F): name(F.name),isSigned(F.isSigned),gradeToSign(F.gradeToSign),gradeToExecute(F.gradeToExecute){}

AForm::~AForm() {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
: name(name),isSigned(false), gradeToSign(gradeToSign),gradeToExecute(gradeToExecute)
{
    if (this->gradeToSign < 1 || this->gradeToExecute < 1)
        throw GradeTooHighException();
    if (this->gradeToSign > 150 || this->gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &other)
{
    if (&other != this)
        this->isSigned = other.isSigned;
    return *this;
}

// METHODS
int AForm::getGradeToSign() const {return gradeToSign;}
int AForm::getGradeToExecute() const {return gradeToExecute;}
std::string AForm::getName() const {return name;}
bool AForm::checkSign() const { return isSigned;}
void AForm::beSigned(Bureaucrat &B)
{
    if (isSigned)
        throw AForm::AlreadySignedException();
    if (B.getGrade() > gradeToSign)
        throw Bureaucrat::GradeTooLowException();
    isSigned = true;
}

// EXCEPTIONS
const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm Grade too hight.";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm Grade too low.";
}
const char *AForm::AlreadySignedException::what() const throw()
{
	return "AForm Already signed.";
}
const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form Not Signed.";
}

// OPERATORS
std::ostream &operator<<(std::ostream &out, const AForm &F)
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