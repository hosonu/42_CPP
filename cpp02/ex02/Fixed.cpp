#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
}


Fixed::Fixed(const int n) {
	this->value = n << fractionalBits;
}

Fixed::Fixed(const float f) {
	this->value = roundf(f * (1 << fractionalBits));
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed &rhs) {
	this->value = rhs.getRawBits();
	return *this;
}

Fixed &Fixed::operator+(Fixed const &rhs) {
	this->value += rhs.getRawBits();
	return *this;
}

Fixed& Fixed::operator-(Fixed const &rhs) {
	this->value -= rhs.getRawBits();
	return *this;
}

Fixed& Fixed::operator*(Fixed const &rhs) {
	this->value *= rhs.getRawBits() >> fractionalBits;
	return *this;
}

Fixed& Fixed::operator/(Fixed const &rhs) {
	this->value /= rhs.getRawBits() << fractionalBits;
	return *this;
}

bool Fixed::operator<(Fixed const &rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>(Fixed const &rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}

Fixed& Fixed::operator++() {
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed& Fixed::operator--() {
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

Fixed const& Fixed::min(Fixed const &a, Fixed const &b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

Fixed const& Fixed::max(Fixed const &a, Fixed const &b) {
	return (a > b) ? a : b;
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
