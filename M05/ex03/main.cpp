#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    try
    {
        Bureaucrat B = Bureaucrat();
        // AForm F = AForm("id", 20, 11);
        // // B.decrementGrade();
        // // B.incrementGrade();
        // // Bureaucrat B2 = Bureaucrat("Henry Kissinger", 200);
        // Bureaucrat B2 = Bureaucrat("Henry Kissinger", 15);
        // B2.signForm(F);
        // B2.signForm(F);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}