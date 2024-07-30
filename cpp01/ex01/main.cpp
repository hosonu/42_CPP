# include "Zombie.hpp"


std::string getValidInput(const std::string& prompt) {
	std::string input;

	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << "Don't push Ctr + D!!!!!";	
			}
			exit(1);
		}
		if (!input.empty() && input.find_first_not_of(' ') != std::string::npos)
			break;
		std::cout << "Invalid input. Please enter a non-empty string." << std::endl;
	}
	return input;
}

int main(void) {
	int N;
	std::string input;

	std::cout << "Enter index to display: ";
	while (true) {
		input = getValidInput("");
		std::stringstream ss(input);
		if (ss >> N && ss.eof()) {
			break;
		}
		std::cout << "Invalid input. Please enter a number: ";
	}
	Zombie *zombiz = zombieHorde(N, "zombie");

	for (int i = 0; i < N; i++) {
		zombiz[i].announce();
	}

	delete [] zombiz;
	return 0; 
}
