#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), target_(target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src) {
	this->target_ = src.target_;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->target_ = rhs.target_;
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & excutor) const {
	if (this->getSigned() == false)
		throw FormNotSignedException();
	if (excutor.getGrade() > this->getGradetoExecute())
		throw GradeTooLowException();

	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox."	 << std::endl;
}