#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat(const std::string &type);
		~WrongCat();

		WrongCat &operator=(const WrongCat &other);

		void	makeSound();
		std::string	getType(void) const;
};

#endif
