#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_(NULL), grade_(0) {
}

Bureaucrat::~Bureaucrat() {
	std::cout << "destrcutor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs) {
	std::cout << "Bureacurat assignmention operator called" 
}