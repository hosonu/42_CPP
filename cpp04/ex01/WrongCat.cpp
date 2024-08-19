#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat distructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Meow Meow Meow" << std::endl;
}