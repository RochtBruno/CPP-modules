#ifndef DOG__HPP
#define DOG__HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &other);
		Dog(const std::string &type);
		~Dog();

		Dog &operator=(const Dog &other);

		void	makeSound();
		std::string	getType(void) const;
};

#endif
