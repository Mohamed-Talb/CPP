#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat B = Bureaucrat();
        Form F = Form("Chahadat Sokna", 20, 11);
        // B.decrementGrade();
        // B.incrementGrade();
        // Bureaucrat B2 = Bureaucrat("Henry Kissinger", 200);
        Bureaucrat B2 = Bureaucrat("Lem9adem", 15);
        B2.signForm(F);
        B2.signForm(F);
		std::cout << F << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}