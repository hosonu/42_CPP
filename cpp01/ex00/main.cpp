# include "Zombie.hpp"

int main(void) {
	std::string name;

	std::cout << "Creating zombie on the stack." << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie zombie1(name);
	zombie1.announce();

	std::cout << "Creating zombie on the heap." << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie *zombie2 = newZombie(name);
	zombie2->announce();
	delete zombie2;

	randomChump("RandomZombie");
	return (0);
}
