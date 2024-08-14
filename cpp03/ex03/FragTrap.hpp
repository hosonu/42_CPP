# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public :
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &src);
		FragTrap	&operator=(const FragTrap &rhs);
		virtual ~FragTrap();

		virtual void attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif
