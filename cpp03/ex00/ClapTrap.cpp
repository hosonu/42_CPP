#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {	
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap named constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : name(src.name), hitPoints(src.hitPoints),  energyPoints(src.energyPoints), attackDamage(src.attackDamage) {
	std::cout << "ClapTrap copy constructor called for " << name << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
    } else if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " can't attack because it has no hit points left!" << std::endl;
    } else {
		std::cout << "ClapTrap " << name << " can't attack because it has no energy points left!" << std::endl;
    }
}

void	ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0) {
        if (amount >= hitPoints) {
        	hitPoints = 0;
    		std::cout << "ClapTrap " << name << " takes " << amount << " damage and is destroyed!" << std::endl;
        } else {
        	hitPoints -= amount;
        	std::cout << "ClapTrap " << name << " takes " << amount << " damage, reducing its hit points to " << hitPoints << "!" << std::endl;
        }
    } else {
    	std::cout << "ClapTrap " << name << " is already destroyed and can't take more damage!" << std::endl;
    }
}

void	ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
    	hitPoints += amount;
    	energyPoints--;
    	std::cout << "ClapTrap " << name << " repairs itself, gaining " << amount << " hit points! It now has " << hitPoints << " hit points." << std::endl;
	} else if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " can't be repaired because it has no hit points left!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " can't be repaired because it has no energy points left!" << std::endl;
	}
}
