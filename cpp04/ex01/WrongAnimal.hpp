#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "iostream"

class WrongAnimal {
	protected :
		std::string	type;
	
	public :
		WrongAnimal();
		WrongAnimal(const std::string type);
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal&	operator=(const WrongAnimal &rhs);
		~WrongAnimal();

		void	makeSound() const;
		std::string getType() const;
};

#endif
