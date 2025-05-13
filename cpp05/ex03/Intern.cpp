#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src) {
	std::cout << "Intern assignment operator called" << std::endl;
	if (this != &src) {
		//não tem atributo para copiar
	}
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	std::cout << "Intern creates " << formName << " form" << std::endl;
	if (formName == "robotomy request") {
		return new RobotomyRequestForm(target);
	} else if (formName == "presidential pardon") {
		return new PresidentialPardonForm(target);
	} else if (formName == "shrubbery creation") {
		return new ShrubberyCreationForm(target);
	} else {
		std::cerr << "Error: Form not found" << std::endl;
		return NULL;
	}
}
