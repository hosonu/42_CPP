#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMAL_COUNT 10

int main()
{
	Animal* animals[ANIMAL_COUNT];

	for (int i = 0; i < ANIMAL_COUNT; i++) {
		if (i < ANIMAL_COUNT / 2) {
			std::cout << "Creating Dog " << i << std::endl;
			animals[i] = new Dog();
			animals[i]->makeSound();
		}
		else {
			std::cout << "Creating Cat " << i << std::endl;
			animals[i] = new Cat();
			animals[i]->makeSound();
		}
    }

	std::cout << "\nTesting deep copy:" << std::endl;
	Dog* originalDog = new Dog();
	Dog* copiedDog = new Dog(*originalDog);
	delete originalDog;
	std::cout << "Copied Dog should still have its Brain after original is deleted." << std::endl;
    delete copiedDog;

	std::cout << "\nDeleting all animals:" << std::endl;
	for (int i = 0; i < ANIMAL_COUNT; i++) {
		std::cout << "Deleting animal " << i << std::endl;
		delete animals[i];
	}

	return 0;
}
