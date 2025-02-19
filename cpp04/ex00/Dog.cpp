#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type) {
	std::cout << "Dog type constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	Animal::operator=(other);
	std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}

void	Dog::makeSound() {
	std::cout << this->_type << " RUF RUF" << std::endl;
}

std::string	Dog::getType(void) const {
	return Animal::getType();
}


