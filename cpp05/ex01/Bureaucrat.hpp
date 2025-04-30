#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();

		//Chamado automaticamente quando um novo objeto é criado a partir de um objeto já existente.
		//Ele inicializa o novo objeto com os valores do objeto passado como argumento.
		Bureaucrat(Bureaucrat const &other);

		//Chamado quando um objeto já existente recebe os valores de outro objeto do mesmo tipo.
		//Ele copia os valores do objeto passado, substituindo os valores do objeto que já existia.
		Bureaucrat &operator=(Bureaucrat const &other);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		setGrade(int grade);
		void		incrementGrade();
		void		decrementGrade();

		void	signForm();
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
