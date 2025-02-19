#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
	std::cout << "Animal type constructor called" << std::endl;
}

void	Animal::makeSound() {
	std::cout << "Animal sound" << std::endl;
}

std::string	Animal::getType(void) const {
	return this->_type;
}


