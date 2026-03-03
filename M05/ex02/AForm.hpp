#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"

class AForm
{
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        // CANONICAL AForm
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &F);
		AForm &operator=(const AForm &other);
		~AForm();

        // GETTERS
        bool checkSign() const;
        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
		void beSigned(Bureaucrat &B);
		virtual void execute(Bureaucrat const &executor) const = 0;
        
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
		class FormNotSignedException: public std::exception
		{
			public:
			virtual const char *what() const throw();
		};
};

#endif