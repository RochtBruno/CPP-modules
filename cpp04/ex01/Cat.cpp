#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type) {
	std::cout << "Cat type constructor called" << std::endl;
}

void	Cat::makeSound() const{
	std::cout << this->_type << "MIAU sound" << std::endl;
}

std::string	Cat::getType(void) const {
	return this->_type;
}
