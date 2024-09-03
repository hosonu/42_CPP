#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern &src);
		Intern& operator=(const Intern &rhs);
		AForm*	makeForm(std::string formName, std::string target);
};

#endif
