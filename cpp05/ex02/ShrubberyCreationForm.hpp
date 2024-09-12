#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private :
		std::string target_;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
		void execute(Bureaucrat const & executor) const;
};

#endif
