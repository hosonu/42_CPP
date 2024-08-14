#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	Hoyuki("Hoyuki");
	/* Test */
	std::cout << "\nStart attacking...\n" << std::endl;

	Hoyuki.attack("Girl");
	Hoyuki.attack("KOJI");
	Hoyuki.takeDamage(3);
	Hoyuki.takeDamage(4);
	Hoyuki.beRepaired(10);
	Hoyuki.attack("Dragon");
	Hoyuki.attack("Spirits");
	Hoyuki.attack("Lions");
	Hoyuki.attack("Kings");

	std::cout << "\nFights are over..." << std::endl;
}