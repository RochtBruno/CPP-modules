#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other) , _brain(new Brain(*other._brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::Dog(const std::string &type) : AAnimal(type) {
	std::cout << "Dog type constructor called" << std::endl;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other)
		_type = other._type;

	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	return *this;
}

void	Dog::makeSound() const{
	std::cout << this->_type << " RUF RUF" << std::endl;
}

std::string	Dog::getType(void) const {
	return AAnimal::getType();
}


