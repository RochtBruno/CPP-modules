#pragma once

#include <iostream>
#include <exception>

class Bureaucrat;

class Form{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_required;
		const int			_grade_to_exec;

	public:
		Form(void);
		Form(const std::string &name,int grade_required, int grade_to_exec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);
	
		std::string	getName(void) const;
		int			getSigned() const;
		int			getGradeRequired() const;
		int			getGradeToExec()const;

		void		beSigned(const Bureaucrat &other);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
};

std::ostream &operator<<(std::ostream &os, Form const &form);