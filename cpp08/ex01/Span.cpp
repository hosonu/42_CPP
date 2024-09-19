#include "Span.hpp"

Span::Span() : N(0) {
	numbers.reserve(0);
}

Span::Span(unsigned int N) : N(N) {
	numbers.reserve(N);
}

Span::Span(const Span &src) : N(src.N), numbers(src.numbers) {
}

Span& Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->N = rhs.N;
		this->numbers = rhs.numbers;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int num) {
	if (numbers.size() >= N)
		throw FullSpanException();
	numbers.push_back(num);
}

unsigned int	Span::shortestSpan() {
	if (numbers.size() < 2) {
		throw InsufficientElementsException();
	}

	std::sort(numbers.begin(), numbers.end());
	std::vector<unsigned int> differences(numbers.size() - 1);
	std::adjacent_difference(numbers.begin(), numbers.end(), differences.begin());
	// for(int i = 0; i < 2; i++)
	// 	std::cout << differences[i] << std::endl;
	return *std::min_element(differences.begin() + 1, differences.end());
}

unsigned int	Span::longestSpan() {
	if (numbers.size() < 2) {
		throw InsufficientElementsException();
	}
	std::sort(numbers.begin(), numbers.end());
	return static_cast<unsigned int>(numbers.back() - numbers.front());
}

const char* Span::FullSpanException::what() const throw() {
	return "Span is already full";
}

const char* Span::InsufficientElementsException::what() const throw() {
	return "Not enough elements to caluculate span";
}