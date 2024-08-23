#include "Dog.hpp"

Dog::Dog() : Aanimal("Dog") {
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Aanimal(src) {
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &rhs) {
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
		this->type = rhs.type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const{
	std::cout << "Bow Bow Bow" << std::endl;
}
