#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "--------------Animal----------------"  << std::endl; 

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl  << "-------------Wrong Animal----------------" << std::endl;


 	const WrongAnimal *wrong = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

    std::cout << "Wrong Type: " << wrong->getType() << std::endl;
    std::cout << "WrongCat Type: " << wrongCat->getType() << std::endl;
    wrong->makeSound();
    wrongCat->makeSound();

	delete wrong;
	delete wrongCat;

	return 0;
}
