#include "Intern.hpp"
int main()
{
	Bureaucrat B1("Mohammed VI", 1);
	Bureaucrat B2("Henry Kissinger", 75);
	Bureaucrat B3("M9adem", 130);

	Intern someRandomIntern;

	AForm* SHF = NULL;
	AForm* RRF = NULL;
	AForm* PPF = NULL;
	AForm* WRONG = NULL;
    try
    {

        SHF = someRandomIntern.makeForm("shrubbery creation", "Bita9a");
        RRF = someRandomIntern.makeForm("robotomy request", "build a house");
        PPF = someRandomIntern.makeForm("presidential pardon", "Someone");
        WRONG = someRandomIntern.makeForm("unknown form", "target");

        std::cout << *SHF << std::endl;
        std::cout << *RRF << std::endl;
        std::cout << *PPF << std::endl;

        B1.signForm(*PPF);
        B1.executeForm(*PPF);

        B2.signForm(*RRF);
        B2.executeForm(*RRF);

        B3.signForm(*SHF);
        B3.executeForm(*SHF);

        delete SHF;
        delete RRF;
        delete PPF;
        delete WRONG;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
		if (SHF)
			delete SHF;
        if (RRF)
			delete RRF;
		if (PPF)
        	delete PPF;
        if (WRONG)
			delete WRONG;
    }
}