#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {
	private:
		unsigned int N;
		std::vector<int> numbers;

	public:
		Span(unsigned int N);
		~Span();

		void	addNumber(int num);
		int	shortestSpan() const;
		int	longestSpan() const;

		class FullSpanException : public std::exception {
			public:
				virtual const char* what() const throw();
		}

		class InsufficientElementsException : public std::exception {
   			public:
        		virtual const char* what() const throw();
		}

};

#endif
