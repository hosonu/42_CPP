#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try
	{
		Bureaucrat b("hoyuki", 20);
		Bureaucrat b1("himari", 60);
		Form f1("Form1", 40, 25);
		Form f2("Form2", 19, 16);

		std::cout << b << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

		b.signForm(f1);
		b.signForm(f2);

		b1.signForm(f1);
		b1.signForm(f2);
		
		// b.incrementGrade();
		// b.incrementGrade();
		// std::cout << b << std::endl;
		// b.signForm(f2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}	
