#pragma once

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_required;
		const int			_grade_to_exec;

	public:
		AForm(void);
		AForm(const std::string &name,int grade_required, int grade_to_exec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm(void);

		std::string		getName(void) const;
		int				getSigned() const;
		int				getGradeRequired() const;
		int				getGradeToExec()const;

		void			beSigned(const Bureaucrat &other);

		virtual void	execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream &os, AForm const &Aform);
