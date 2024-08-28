#include "AForm.hpp"

AForm::AForm() : name_(""), is_sign(false), gradetoSign_(30), gradetoExecute_(50) {
}

AForm::AForm(const std::string name, int gradetoSign, int gradetoExecute) 
: name_(name), gradetoSign_(gradetoSign), gradetoExecute_(gradetoExecute) {
	is_sign = false;
	if (gradetoSign < 1 || gradetoExecute < 1)
		throw GradeTooHighException();
	else if (gradetoSign > 150 || gradetoExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &src) : name_(src.name_), is_sign(src.is_sign), gradetoSign_(src.gradetoSign_), gradetoExecute_(src.gradetoExecute_){}

AForm& AForm::operator=(const AForm &rhs) {
	if (this != &rhs) {
		this->is_sign = rhs.getSigned();
		std::cout << "Just subtitude <is_sign>" << std::endl;
	}
	return *this;
}

std::string AForm::getName() const {
	return (this->name_);
}

bool	AForm::getSigned() const {
	return (this->is_sign);
}

int AForm::getGradetoSign() const {
	return (this->gradetoSign_);
}

int AForm::getGradetoExecute() const {
	return (this->gradetoExecute_);
}

void AForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= this->gradetoSign_)
		this->is_sign = true;
	else
		throw GradeTooLowException();
}


std::ostream &operator<<(std::ostream &out, AForm const &src)
{	
	out << src.getName() << ", grade to sign " << src.getGradetoSign() << ", grade to execute " << src.getGradetoExecute(); 
	return (out);
}