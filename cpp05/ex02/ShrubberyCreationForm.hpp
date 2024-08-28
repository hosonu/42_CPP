#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubeeyCreationForm : public AForm {
	private :
		std::string target_;
	public :
		ShrubeeyCreationForm(std::string target = "");
		~ShrubeeyCreationForm();
		ShrubeeyCreationForm(const ShrubeeyCreationForm &src);
		ShrubeeyCreationForm& operator=(const ShrubeeyCreationForm &rhs);
		void execute(Bureaucrat const & executor) const;
};

#endif
