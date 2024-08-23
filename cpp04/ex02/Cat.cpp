#include "Cat.hpp"

Cat::Cat() : Aanimal("Cat") {
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Aanimal(src) {
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &rhs) {
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
		this->type = rhs.type;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow Meow" << std::endl;
}
