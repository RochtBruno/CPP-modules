#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal &other);
		Animal(const std::string &type);
		virtual ~Animal();

		Animal &operator=(const Animal &other);

		virtual void	makeSound() const; // virtual serve para indicar ao compilador que a função será volátil.
		std::string		getType(void) const;
};


#endif
