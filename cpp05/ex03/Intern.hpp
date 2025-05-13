#pragma once
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

class Intern{
public:
	Intern();
	Intern(const Intern &src);
	~Intern();
	Intern &operator=(const Intern &src);

	AForm *makeForm(std::string formName, std::string target);
};


