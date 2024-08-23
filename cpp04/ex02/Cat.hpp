#ifndef CAT_HPP
#define CAT_HPP

#include "Aanimal.hpp"
#include "Brain.hpp"

class Cat : public	Aanimal {
	private:
		Brain	*brain;
	public :
		Cat();
		Cat(const Cat &src);
		Cat &operator=(const Cat &rhs);
		~Cat();
		void	makeSound() const ;
};

#endif
