#include <iostream>

class Bureaucrat
{
	const std::string name;
	int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &B);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const; 
		class GradeTooHighException: public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooHighException()
				~GradeTooHighException()
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			private:
				std::string message;
			public:
				virtual const char *what() const throw();
		};
};