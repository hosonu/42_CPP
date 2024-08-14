#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	std::cout << "FragTrap copy constructor called for " << name << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << name << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "FragTrap " << name << " can't attack due to lack of energy or hit points!" << std::endl;
	}
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " says [High Fives Guys!]" << std::endl;
}
