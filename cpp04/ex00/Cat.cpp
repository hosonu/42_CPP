#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow Meow" << std::endl;
}
