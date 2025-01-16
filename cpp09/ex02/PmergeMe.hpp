#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

template <typename Container>
void	insertIntoMainChain(Container& mainChain, typename Container::value_type element) {
	typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), element);
	mainChain.insert(pos, element);
}

template <typename Container>
void	mergeInsertSort(Container& container) {
	int n = container.size();

	if (n <= 1) {
		return;
	}

	Container largeElements, smallElements;
	for (int i = 0; i < n / 2; ++i) {
		if (container[2 * i] > container[2 * i + 1]) {
			largeElements.push_back(container[2 * i]);
			smallElements.push_back(container[2 * i + 1]);
		} else {
			largeElements.push_back(container[2 * i + 1]);
			smallElements.push_back(container[2 * i]);
		}
	}

	if (n % 2 != 0) {
		largeElements.push_back(container.back());
	}

	mergeInsertSort(largeElements);

	Container mainChain = largeElements;

	for (size_t i = 0; i < smallElements.size(); ++i) {
		insertIntoMainChain(mainChain, smallElements[i]);
	}

	container = mainChain;
}

template <typename Container>
void printContainer(const Container& container) {
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

class PmergeMe {
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		std::clock_t		_start_vector;
		std::clock_t		_end_vector;
		std::clock_t		_start_deque;
		std::clock_t		_end_deque;
		
	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe();
		void	mergeInsertSortVector();
		void	mergeInsertSortDeque();
		void	printContainers();
};

#endif
