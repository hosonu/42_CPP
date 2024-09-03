#include "Form.hpp"

Form::Form() : name_(""), is_sign(false), gradetoSign_(30), gradetoExecute_(50) {
}

Form::Form(const std::string name, int gradetoSign, int gradetoExecute) 
: name_(name), gradetoSign_(gradetoSign), gradetoExecute_(gradetoExecute) {
	is_sign = false;
	if (gradetoSign < 1 || gradetoExecute < 1)
		throw GradeTooHighException();
	else if (gradetoSign > 150 || gradetoExecute > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &src) : name_(src.name_), is_sign(src.is_sign), gradetoSign_(src.gradetoSign_), gradetoExecute_(src.gradetoExecute_){}

Form& Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		this->is_sign = rhs.getSigned();
	}
	return *this;
}

std::string Form::getName() const {
	return (this->name_);
}

bool	Form::getSigned() const {
	return (this->is_sign);
}

int Form::getGradetoSign() const {
	return (this->gradetoSign_);
}

int Form::getGradetoExecute() const {
	return (this->gradetoExecute_);
}

void Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= this->gradetoSign_)
		this->is_sign = true;
	else
		throw GradeTooLowException();
}


std::ostream &operator<<(std::ostream &out, Form const &src)
{	
	out << src.getName() << ", Form is signed " << src.getSigned() << ", grade to sign " << src.getGradetoSign() << ", grade to execute " << src.getGradetoExecute(); 
	return (out);
}