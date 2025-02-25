#ifndef DOG__HPP
#define DOG__HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &other);
		Dog(const std::string &type);
		~Dog();

		Dog &operator=(const Dog &other);

		void	makeSound() const;
		std::string	getType(void) const;
	private:
		Brain *_brain;

};

#endif
