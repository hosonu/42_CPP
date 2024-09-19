#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <numeric>
#include <iostream>


class Span {
	private:
		unsigned int N;
		std::vector<int> numbers;

	public:
		Span();
		Span(const Span &src);
		Span& operator=(const Span &rhs);
		Span(unsigned int N);
		~Span();

		void	addNumber(int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class FullSpanException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class InsufficientElementsException : public std::exception {
   			public:
        		virtual const char* what() const throw();
		};

};

#endif
