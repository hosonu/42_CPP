#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
	private :
		const std::string name_;
		bool	is_signe;
		const int gradetoSign_;
		const int gradetoExecute_;
	public :
		Form();
		Form(const std::string name, int gradetoSign, int gradetoExecute);
		~Form();
		Form(const Form &src);
		Form &operator=(const Form &rhs);
		std::string getName() const;
		bool	getSigned(Bureaucrat &b) const;
		int	getGradetoSign() const;
		int getGradetoExecute() const;
		void	beSigned() const;

		class GradeTooLowException : public std::exception {};
		class GradeTooHighException : public std::exception {};
};

std::ostream& operator<<(std::ostream &out, const Form &src);

#endif
