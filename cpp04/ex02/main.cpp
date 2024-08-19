#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;
	delete i;
	

	const Animal* animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
	for(int i = 0; i < 4; i++)
		delete animals[i];


	return 0;
}
