#include "Span.hpp"
#include <iostream>

int main()
{
	try {
		Span sp = Span(5);
		// sp.addNumber(2147483647);
		// sp.addNumber(-2147483648);
		sp.addNumber(17);
		sp.addNumber(2);
		sp.addNumber(1);
		sp.addNumber(9);
		sp.addNumber(2);
		// sp.addNumber(2);
		// sp.addNumber(3);
		// sp.addNumber(3);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
