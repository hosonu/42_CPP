#ifndef AANIMAL_HPP
#define AANIMAL_HPP

# include <iostream>

class Aanimal {
	protected :
		std::string	type;
	
	public :
		Aanimal();
		Aanimal(const std::string type);
		Aanimal(const Aanimal &src);
		Aanimal&	operator=(const Aanimal &rhs);
		virtual ~Aanimal();

		virtual void	makeSound() const = 0;
		std::string getType() const;
};

#endif
