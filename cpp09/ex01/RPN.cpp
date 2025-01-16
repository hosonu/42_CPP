#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	if (this != &other) {
		this->_stack = other._stack;
	}
}

RPN::~RPN() {
	while (!this->_stack.empty()) {
		this->_stack.pop();
	}
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

void	RPN::execute(const std::string &expression) {
	std::istringstream	ss(expression);
	std::string			token;

	while (ss >> token) {
		if (isdigit(token[0])) {
			int num = std::strtoll(token.c_str(), NULL, 10);
			if (num < 0 || num > 9) {
				throw std::runtime_error("Error: invalid number");
			}
			this->_stack.push(num);
		} else if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (this->_stack.size() < 2) {
				throw std::runtime_error("Error: not enough operands");
			}
			int second = this->_stack.top();
			this->_stack.pop();
			int first = this->_stack.top();
			this->_stack.pop();

			switch (token[0]) {
				case '+':
					this->_stack.push(first + second);
					break;
				case '-':
					this->_stack.push(first - second);
					break;
				case '*':
					this->_stack.push(first * second);
					break;
				case '/':
					if (second == 0) {
						throw std::runtime_error("Error: division by zero");
					}
					this->_stack.push(first / second);
					break;
				default:
					throw std::runtime_error("Error: invalid operator");	
			}
		} else {
			throw std::runtime_error("Error: invalid token");
		}
	}

	if (this->_stack.size() != 1) {
		throw std::runtime_error("Error: invalid expression");
	}

	std::cout << this->_stack.top() << std::endl;
}