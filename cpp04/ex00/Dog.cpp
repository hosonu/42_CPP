#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog distructor called" << std::endl;
}

void	Dog::makeSound() const{
	std::cout << "Bow Bow Bow" << std::endl;
}
