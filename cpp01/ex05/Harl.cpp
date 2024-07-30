#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void	Harl::debug( void ) {
	std::cout << "DEBUG" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "INFO" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "WARNING" << std::endl;
}

void	Harl::error( void ) {
	std::cout << "ERROR" << std::endl;
}