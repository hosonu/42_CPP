#include "Bureaucrat.hpp"

int main() {
	try
	{
		Bureaucrat b("hoyuki", 2);
		// b.decremnetGrade();
		// b.decremnetGrade();
		// b.decremnetGrade();
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}