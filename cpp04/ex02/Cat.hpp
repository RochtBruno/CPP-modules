#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	public:
		Cat();
		Cat(const Cat &other);
		Cat(const std::string &type);
		~Cat();

		Cat &operator=(const Cat &other);

		void	makeSound() const;
		std::string	getType(void) const;
	private:
		Brain *_brain;
};

#endif
