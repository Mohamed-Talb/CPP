#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat B = Bureaucrat();
        // AForm F = AForm("id", 20, 11);
        // // B.decrementGrade();
        // // B.incrementGrade();
        // // Bureaucrat B2 = Bureaucrat("Henry Kissinger", 200);
        Bureaucrat B1 = Bureaucrat("Mohammed VI", 1);
        Bureaucrat B2 = Bureaucrat("Henry Kissinger", 75);
        Bureaucrat B3 = Bureaucrat("M9adem", 130);
		ShrubberyCreationForm SHF = ShrubberyCreationForm("Bita9a", "Someone");
		RobotomyRequestForm RRF = RobotomyRequestForm("ro5sa", "build a house");
		PresidentialPardonForm PPF = PresidentialPardonForm();
		std::cout << SHF << std::endl;
		std::cout << RRF << std::endl;
		std::cout << PPF << std::endl;
        B1.signForm(PPF);
        B1.executeForm(PPF);
        
		B2.signForm(RRF);
        B2.executeForm(RRF);
        
		B3.signForm(SHF);
        B3.executeForm(SHF);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}