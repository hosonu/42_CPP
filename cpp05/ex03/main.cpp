#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	try
	{
		Intern	intern;
		Bureaucrat b("Hoyuki", 50);

		AForm* form1 = intern.makeForm("PresidentialPardonForm", "Target1");
		AForm* form2 = intern.makeForm("RobotomyRequestForm", "Target2");
		AForm* form3 = intern.makeForm("ShrubberyCreationForm", "Target3");
		if (form1) {
			b.signForm(*form1);
			b.executeForm(*form1);
			delete form1;
		}
        if (form2) {
			b.signForm(*form2);
			b.executeForm(*form2);
			delete form2;
		}
		if (form3) {
			b.signForm(*form3);
			b.executeForm(*form3);
			delete form3;
		}
		AForm* form4 = intern.makeForm("UnknownForm", "Target4");
        if (!form4) {}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}	
