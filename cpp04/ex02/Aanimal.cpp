#include "Aanimal.hpp"

Aanimal::Aanimal() : type("Aanimal") {
	std::cout << "Aanimal constructor called" << std::endl;
}

Aanimal::Aanimal(const std::string type) : type(type) {
	std::cout << "Aanimal constructor called for " << this->type << std::endl;
}

Aanimal::Aanimal(const Aanimal &src) {
	std::cout << "Aanimal copy constructor called" << std::endl;
	*this = src;
}

Aanimal&	Aanimal::operator=(const Aanimal &rhs) {
	std::cout << "Aanimal assignment operetor called" << std::endl;
	if ( this != &rhs ) {
        this->type = rhs.type;
    }
    return *this;
}

Aanimal::~Aanimal() {
	std::cout << "Aanimal destructor called" << std::endl;
}

void	Aanimal::makeSound() const {
	std::cout << "Aanimal makeSound called" << std::endl;
}

std::string Aanimal::getType() const {
	return this->type;
}
