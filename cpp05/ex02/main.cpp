#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try
	{
		Bureaucrat b("hoyuki", 2);
		Form f1("Form1", 4, 50);
		Form f2("Form2", 1, 60);

		std::cout << b << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

		b.signForm(f1);
		b.signForm(f2);

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}	
