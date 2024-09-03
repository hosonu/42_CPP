#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private :
		const std::string name_;
		bool	is_sign;
		const int gradetoSign_;
		const int gradetoExecute_;
	public :
		Form();
		Form(const std::string name, int gradetoSign, int gradetoExecute);
		~Form();
		Form(const Form &src);
		Form &operator=(const Form &rhs);
		
		std::string getName() const;
		bool		getSigned() const;
		int			getGradetoSign() const;
		int 		getGradetoExecute() const;
		void		beSigned(Bureaucrat &b);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too high for this form.";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too low for this form.";
				}
		};
};

std::ostream& operator<<(std::ostream &out, const Form &src);

#endif
