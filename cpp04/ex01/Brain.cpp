#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
	*this = src;
}

Brain& Brain::operator=(const Brain &rhs) {

}

Brain::~Brain() {
	std::cout << "Brain distructor called" << std::endl;
}