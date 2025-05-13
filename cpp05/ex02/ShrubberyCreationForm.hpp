#pragma once

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm(void);

		void execute(const Bureaucrat &executor) const;

		class OpenFileException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};



// std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form);
