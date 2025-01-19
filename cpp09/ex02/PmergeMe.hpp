#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

extern int	cnt;

struct ComparisonCounter {
    int& counter;
    ComparisonCounter(int& c) : counter(c) {}
    bool operator()(int a, int b) {
        ++counter;
        return a < b;
    }
};

std::vector<size_t> generateJacobsthalIndices(size_t size);

template <typename Container>
void	createSortedPairs(const Container& input, Container& largeElements, Container& smallElements) {
	for (size_t i = 0; i < input.size() / 2; ++i) {
		if (input[2 * i] > input[2 * i + 1]) {
			largeElements.push_back(input[2 * i]);
			smallElements.push_back(input[2 * i + 1]);
			++cnt;
		} else {
			largeElements.push_back(input[2 * i + 1]);
			smallElements.push_back(input[2 * i]);
			++cnt;
		}
	}

	if (input.size() % 2 != 0) {
		smallElements.push_back(input[input.size() - 1]);
	}
}

template <typename Container>
void reorderSmallElements(Container& smallElements, const Container& largeElements, const Container& originalContainer) {
    Container tempSmall = smallElements;
	Container resultSmall = smallElements;
    for (size_t i = 0; i < largeElements.size(); ++i) {
        typename Container::const_iterator pos = std::find(originalContainer.begin(), originalContainer.end(), largeElements[i]);
        if (pos != originalContainer.end()) {
			size_t originalIndex = pos - originalContainer.begin();
			resultSmall[i] = tempSmall[originalIndex / 2];

		}
    }
	smallElements = resultSmall;
}

template <typename Container>
void insertFirstElement(Container& mainChain, const typename Container::value_type& element) {
    typename Container::iterator pos = mainChain.begin();
    mainChain.insert(pos, element);
}

template <typename Container>
void	insertGroupElements(Container& mainChain, Container& largeElements, Container& smallElements, size_t start, size_t end) {
	for (size_t j = end; j > start; --j) {
		if (j - 1 >= smallElements.size()) {
			continue;
		}

		#ifdef DEBUG
			std::cout << "j: " << j << ", largeElements.size(): " << largeElements.size() << std::endl;
		#endif

		if (j >= largeElements.size()) {
			typename Container::iterator insertPos = std::lower_bound(
				mainChain.begin(), mainChain.end(), smallElements[j], ComparisonCounter(cnt)
			);
			mainChain.insert(insertPos, smallElements[j]);
			continue;
		}
		typename Container::iterator pairPos = std::find(
			mainChain.begin(), mainChain.end(), largeElements[j]
		);

		#ifdef DEBUG
			std::cout << "mainChain: ";
			for (typename Container::const_iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
			std::cout << "pairPos: " << *(pairPos) << std::endl;
			std::cout << "smallElements[j]: " << smallElements[j] << std::endl;
		#endif

		if (pairPos == mainChain.end()) {
			typename Container::iterator insertPos = std::lower_bound(
				mainChain.begin(), mainChain.end(), smallElements[j], ComparisonCounter(cnt)
			);
			mainChain.insert(insertPos, smallElements[j]);
			continue;
		}

		typename Container::iterator insertPos = std::lower_bound(
			mainChain.begin(), pairPos - 1 , smallElements[j], ComparisonCounter(cnt)
		);

		mainChain.insert(insertPos, smallElements[j]);
	}
}

template <typename Container>
void	mergeInsertSort(Container& container) {
	int n = container.size();

	if (n <= 1) {
		return;
	}

	Container largeElements, smallElements;
	createSortedPairs(container, largeElements, smallElements);

	mergeInsertSort(largeElements);
	Container mainChain = largeElements;
	
	reorderSmallElements(smallElements, largeElements, container);

	if (!smallElements.empty()) {
		insertFirstElement(mainChain, smallElements[0]);
	}

	std::vector<size_t> jacobsthalIndices = generateJacobsthalIndices(smallElements.size() - 1);

	for (size_t i = 0; i < jacobsthalIndices.size() -1 ; ++i) {
		size_t start = 0, end = 0;
		for (size_t k = 0; k < i; ++k) {
			start += jacobsthalIndices[k];
		}
		for (size_t k = 0; k <= i; ++k) {
			end += jacobsthalIndices[k];
		}

		#ifdef DEBUG
			std::cout << "small elements: ";
			for (typename Container::const_iterator it = smallElements.begin(); it != smallElements.end(); ++it) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		#endif

		insertGroupElements(mainChain, largeElements, smallElements, start, end);
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
