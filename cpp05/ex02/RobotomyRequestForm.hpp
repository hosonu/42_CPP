#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private :
		std::string target_;
	public :
		RobotomyRequestForm(std::string target = "");
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);
		void execute(Bureaucrat const & executor) const;
};

#endif
