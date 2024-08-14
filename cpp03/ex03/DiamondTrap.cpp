# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	this->name = "Default";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap named constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	*this = src;
	std::cout << "DiamondTrap copy cnostructor called for " << this->name << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		this->name = rhs.name;
	}
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << this->name << std::endl;
}

void	DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << this->name << ", and my ClapTrap name is " << ClapTrap::name << std::endl;
}

void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}
