#include "Form.hpp"

Form::Form() : name_(""), is_signe(false), gradetoSign_(30), gradetoExecute_(50) {
}

Form::Form(const std::string name, int gradetoSign, int gradetoExecute) 
: name_(name), gradetoSign_(gradetoSign), gradetoExecute_(gradetoExecute) {
	is_signe = false;
	if (gradetoSign < 1 || gradetoExecute < 1)
		throw GradeTooHighException();
	else if (gradetoSign > 150 || gradetoExecute > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &src) :  name_(src.name_), is_signe(false), gradetoSign_(30), gradetoExecute_(50){
	*this = src;
}