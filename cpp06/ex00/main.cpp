#include "ScalarConverter.hpp"

int main(int ac, char *av[]) {
	if (ac != 2) {
		std::cout << "Invalid Input" << std::endl;
	}
	else
		ScalarConverter::convert(av[1]);
}
