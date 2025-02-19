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
		~Animal();

		Animal &operator=(const Animal &other);

		virtual void	makeSound(); // virtual para fazer o override da função
		std::string		getType(void) const;
};


#endif
