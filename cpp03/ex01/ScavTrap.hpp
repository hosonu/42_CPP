#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public :
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &src);
		ScavTrap	&operator=(const ScavTrap &rhs);
		virtual ~ScavTrap();

		virtual void	attack(const std::string& target);
		void	guardGate();
};

#endif