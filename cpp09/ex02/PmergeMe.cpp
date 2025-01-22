#include "PmergeMe.hpp"

PmergeMe::PmergeMe() 
: _vector(), _deque()
, _start_vector(0), _end_vector(0), _start_deque(0), _end_deque(0) {}

bool	is_number(const std::string &str) {
	if (str.empty()) {
		return false;
	}
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

PmergeMe::PmergeMe(int argc, char **argv) 
: _vector(), _deque()
, _start_vector(0), _end_vector(0), _start_deque(0), _end_deque(0){
	if (argc < 2) {
		throw std::runtime_error("Error: no arguments");
	}

	for (int i = 1; i < argc; i++) {
		if (!is_number(argv[i])) {
			throw std::runtime_error("Error: invalid number");
		}

		long long	num = ft_strtol(argv[i]);
		if (num < 0 || num > INT_MAX) {
			throw std::runtime_error("Error: number out of range");
		}
		this->_vector.push_back(static_cast<int>(num));
		this->_deque.push_back(static_cast<int>(num));
	}
	
	std::srand(std::time(NULL));

	std::cout << "Before: ";
	for (int i = 1; i < argc; i++) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	if (this != &other) {
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {
	this->_vector.clear();
	this->_deque.clear();
}

void	PmergeMe::mergeInsertSortVector() {
	this->_start_vector = std::clock();
	mergeInsertSort(this->_vector);
	this->_end_vector = std::clock();
}

void	PmergeMe::mergeInsertSortDeque() {
	this->_start_deque = std::clock();
	mergeInsertSort(this->_deque);
	this->_end_deque = std::clock();
}

void	PmergeMe::printContainers() {
	std::cout << "After: ";
	//printContainer(this->_vector);
	printContainer(this->_deque);
	double	time_vector = static_cast<double>(this->_end_vector - this->_start_vector) / CLOCKS_PER_SEC * 1000000;
	double	time_deque = static_cast<double>(this->_end_deque - this->_start_deque) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : " << time_vector << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque : " << time_deque << " us" << std::endl;
}

std::vector<size_t> generateJacobsthalIndices(size_t size) {
	std::vector<size_t> indices;
	size_t prev2 = 0, prev1 = 1;

	#ifdef DEBUG
		std::cout << "Small elements size: " << size << std::endl;
	#endif

	if (size == 0) {
		indices.push_back(0);
		return indices;
	}

	while (prev1 < size) {
		indices.push_back(prev1 * 2);
		size_t next = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = next;
	}
	if (indices.empty()) {
		indices.push_back(0);
	}

	#ifdef DEBUG
		std::cout << "indices size: " << indices.size() << std::endl;
	#endif
	return indices;
}

long	ft_strtol(const std::string& str) {
	std::stringstream ss(str);
	long	num;
	ss >> num;
	if (ss.fail()) {
		return 0;
	}
	return num;
} 