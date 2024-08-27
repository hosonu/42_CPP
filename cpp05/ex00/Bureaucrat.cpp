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
	std::cout << name_ << " : destrcutor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs)
	{
		this->grade_ = rhs.getGrade();
		std::cout << "Bureacurat assignmention operator called" << std::endl;
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


std::ostream& operator<<(std::ostream &out, const Bureaucrat &src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return out;
}
