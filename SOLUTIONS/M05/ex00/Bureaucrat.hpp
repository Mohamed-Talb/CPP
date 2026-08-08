#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	const std::string name;
	int grade;
	public:
		// CANONICAL FORM FUNCTIONS
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &B);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		// METHODS
		std::string getName() const;
		int getGrade() const; 
		void incrementGrade();
		void decrementGrade();
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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &B);

#endif