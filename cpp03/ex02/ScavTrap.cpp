#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap named constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called for " << name << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << name << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ScavTrap " << name << " can't attack due to lack of energy or hit points!" << std::endl;
	}
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
