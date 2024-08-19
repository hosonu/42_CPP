#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : type(type) {
	std::cout << "WrongAnimal constructor called for " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &rhs) {
	std::cout << "WrongAnimal assignment operetor called" << std::endl;
	if ( this != &rhs ) {
        this->type = rhs.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal distructor called" << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
