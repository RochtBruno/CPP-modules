#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type) {
	std::cout << "WrongCat type constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	WrongAnimal::operator=(other);
	std::cout << "WrongCat assignation operator called" << std::endl;
	return *this;
}

void	WrongCat::makeSound() {
	std::cout << " **WRONG CAT SOUND**" << std::endl;
}

std::string	WrongCat::getType(void) const {
	return WrongAnimal::getType();
}


