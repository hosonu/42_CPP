#include "RPN.hpp"

int main(int argc, char **argv) {
	/*validate input*/
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
		return 1;
	}

	RPN rpn;
	try {
		rpn.execute(argv[1]);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
