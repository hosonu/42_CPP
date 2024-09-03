#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &src) {
	(void)src;
}

Intern& Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int i = 0;
	while(i < 3 && formName != formNames[i])
		i++;
	switch(i) {
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			throw std::invalid_argument("Form name not recognized");
	}
}