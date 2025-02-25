#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other), _brain(new Brain()) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	return *this;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const std::string &type) : AAnimal(type) {
	std::cout << "Cat type constructor called" << std::endl;
}

void	Cat::makeSound() const{
	std::cout << this->_type << "MIAU sound" << std::endl;
}

std::string	Cat::getType(void) const {
	return this->_type;
}
