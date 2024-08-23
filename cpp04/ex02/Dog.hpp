#ifndef DOG_HPP
#define DOG_HPP

#include "Aanimal.hpp"
#include "Brain.hpp"

class Dog : public Aanimal {
	private :
		Brain *brain;
	public :
		Dog();
		Dog(const Dog &src);
		Dog &operator=(const Dog &rhs);
		~Dog();

		void	makeSound() const;
};

#endif
