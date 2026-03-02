#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat B = Bureaucrat();
        // B.decrementGrade();
        B.incrementGrade();
        Bureaucrat B2 = Bureaucrat("Henry Kissinger", 200);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}