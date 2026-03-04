#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Form
{
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        // CANONICAL FORM
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &F);
		Form &operator=(const Form &other);
		~Form();
        // GETTERS
        bool checkSign() const;
        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
		void beSigned(Bureaucrat &B);
        // EXCEPTIONS
		class GradeTooHighException: public std::exception
		{
			public:
			virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
			virtual const char *what() const throw();
		};
		class AlreadySignedException: public std::exception
		{
			public:
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &F);

#endif