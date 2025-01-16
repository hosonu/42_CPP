#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <exception>
#include <cstdlib>

class RPN {
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN &other);
		~RPN();
		RPN &operator=(const RPN &other);
		void	execute(const std::string &expression);
};

#endif