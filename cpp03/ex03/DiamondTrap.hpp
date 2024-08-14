#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private :
		std::string	name;
	public :
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap	&operator=(const DiamondTrap &rhs);
		virtual ~DiamondTrap();

		void	whoAmI();
		virtual void attack(const std::string& target);
};

#endif
