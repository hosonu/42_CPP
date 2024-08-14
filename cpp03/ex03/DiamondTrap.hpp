#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FlagTrap, public ScavTrap {
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
}

#endif
