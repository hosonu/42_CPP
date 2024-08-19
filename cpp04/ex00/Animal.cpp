#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string type) : type(type) {
	std::cout << "Animal constructor called for " << this->type << std::endl;
}

Animal::Animal(const Animal &src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal&	Animal::operator=(const Animal &rhs) {
	std::cout << "Animal assignment operetor called" << std::endl;
	if ( this != &rhs ) {
        this->type = rhs.type;
    }
    return *this;
}

Animal::~Animal() {
	std::cout << "Animal distructor called" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "Animal makeSound called" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}
