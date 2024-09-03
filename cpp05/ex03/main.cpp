#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try
	{
		Bureaucrat highRank("HighRank", 1);
        Bureaucrat midRank("MidRank", 71);
        Bureaucrat lowRank("LowRank", 150);

		ShrubberyCreationForm scf("Shrubbery");
        RobotomyRequestForm rrf("Robotomy");
        PresidentialPardonForm ppf("Pardon");

		std::cout << "--------------high------------" << std::endl;
		//high rank test
		highRank.signForm(scf);
		highRank.executeForm(scf);
		highRank.signForm(rrf);
		highRank.executeForm(rrf);
		highRank.signForm(ppf);
		highRank.executeForm(ppf);

		std::cout << "\n--------------mid------------" << std::endl;
		//mid rank test
		midRank.signForm(scf);
		midRank.executeForm(scf);
		midRank.signForm(rrf);
		midRank.executeForm(rrf);
		midRank.signForm(ppf);
		midRank.executeForm(ppf);

		std::cout << "\n--------------low------------" << std::endl;
		//low rank test
		lowRank.signForm(scf);
		lowRank.executeForm(scf);
		lowRank.signForm(rrf);
		lowRank.executeForm(rrf);
		lowRank.signForm(ppf);
		lowRank.executeForm(ppf);


		std::cout << "\nTesting execution of unsigned forms:" << std::endl;
        ShrubberyCreationForm unsignedScf("UnsignedShrubbery");
        highRank.executeForm(unsignedScf);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}	
