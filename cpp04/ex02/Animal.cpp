#include "Animal.hpp"

AAnimal::AAnimal() : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type) {
	std::cout << "Animal type constructor called" << std::endl;
}

std::string	AAnimal::getType(void) const {
	return this->_type;
}


