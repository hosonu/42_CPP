# include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N < 0) {
		std::cout << "Don't try it!\n";
		exit(1);
	}
	Zombie *zombiz = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombiz[i].setName(name);
	}
	return zombiz;
}
