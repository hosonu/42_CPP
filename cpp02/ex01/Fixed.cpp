#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->value = n << fractionalBits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(f * (1 << fractionalBits));
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &rhs) {
	this->value = rhs.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat( void ) const{
	return (float)this->value / (float)(1 << fractionalBits);
}

int Fixed::toInt( void ) const {
	return (this->value >> fractionalBits);
}

std::ostream&	operator<<(std::ostream& out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}