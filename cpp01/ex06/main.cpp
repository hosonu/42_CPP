#include "Harl.hpp"

int main(int argc, char *argv[]) {
	Harl	Harl;

	if (argc != 2) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; return 0;
	}
	Harl.complain(argv[1]);
	return 0;
}
