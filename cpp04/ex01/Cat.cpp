#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat distructor called" << std::endl;
}

Cat::Cat(const Cat &src) {
	*this = src;
}

Cat& Cat::operator=(const Cat& rhs) {

}

void	Cat::makeSound() const {
	std::cout << "Meow Meow Meow" << std::endl;
}
