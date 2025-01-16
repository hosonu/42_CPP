#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	try {
		PmergeMe	pmergeMe(argc, argv);
		pmergeMe.mergeInsertSortVector();
		pmergeMe.mergeInsertSortDeque();
		pmergeMe.printContainers();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
