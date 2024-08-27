#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string name_;
		int	grade_;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat& operator=(const Bureaucrat &rhs);


		std::string	getName() const;
		int	getGrade() const;

		void	incrementGrade();
		void	decremnetGrade();

		class GradeTooHighException : public std::exception {};
		class GradeTooLowException : public std::exception {};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &src);

#endif
