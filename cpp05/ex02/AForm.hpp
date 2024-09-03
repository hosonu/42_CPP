#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private :
		const std::string name_;
		bool	is_sign;
		const int gradetoSign_;
		const int gradetoExecute_;
	public :
		AForm();
		AForm(const std::string name, int gradetoSign, int gradetoExecute);
		virtual ~AForm();
		AForm(const AForm &src);
		AForm &operator=(const AForm &rhs);
		
		std::string getName() const;
		bool		getSigned() const;
		int			getGradetoSign() const;
		int 		getGradetoExecute() const;
		void		beSigned(Bureaucrat &b);

		virtual void	execute(Bureaucrat const & executor) const = 0;

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
		class FormNotSignedException : public std::exception {
			public:
        		const char* what() const throw() {
            		return "Form is not signed.";
        		}
		};
};

std::ostream& operator<<(std::ostream &out, const AForm &src);

#endif
