#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_(""), grade_(0) {
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name), grade_(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}


Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name_(src.name_), grade_(src.grade_) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs)
	{
		this->grade_ = rhs.getGrade();
		std::cout << "Just subtitude <is_sign>" << std::endl;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
	return (this->name_);
}

int	Bureaucrat::getGrade() const {
	return (this->grade_);
}

void	Bureaucrat::incrementGrade() {
	if (grade_ <= 1) {
		throw GradeTooHighException();
	}
	grade_--;
}

void	Bureaucrat::decremnetGrade() {
	if (grade_ >= 150) {
		throw GradeTooLowException();
	}
	grade_++;
}

void	Bureaucrat::signForm(Form &f) {
	try
	{
		f.beSigned(*this);
		std::cout << *this << " signed " << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " couldn't sign " << f << " because " << e.what() << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return out;
}
