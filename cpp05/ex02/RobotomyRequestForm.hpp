#pragma once

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm(void);

		void execute(const Bureaucrat &executor) const;

		class OpenFileException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
