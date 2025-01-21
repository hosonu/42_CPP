#include "PmergeMe.hpp"

int cnt = 0;

int	main(int argc, char **argv) {
	try {
		PmergeMe	pmergeMe(argc, argv);
		pmergeMe.mergeInsertSortVector();
		pmergeMe.mergeInsertSortDeque();
		pmergeMe.printContainers();
		std::cout << "Number of comparisons: " << cnt << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
