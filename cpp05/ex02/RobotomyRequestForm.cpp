#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), target_("target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), target_(target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src) {
	this->target_ = src.target_;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs) {
		this->target_ = rhs.target_; 
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() == false)
		throw FormNotSignedException();
	if(executor.getGrade() > this->getGradetoExecute())
		throw GradeTooLowException();
	
	std::cout << " Drilling noises " << std::endl;

	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0) {
		std::cout << this->target_ << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed for " << this->target_ << "." << std::endl;
	}
}