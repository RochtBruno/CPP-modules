#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
	std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name,int grade) : _name(name){
	std::cout << "Name and grade constructor called." << std::endl;
	setGrade(grade);
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade){
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	if(this != &other)
		_grade = other._grade;

	std::cout << "Assignment operator called for " << this->_name << std::endl;
	return *this;
}

const char * Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade is too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade is too low");
}

std::string	Bureaucrat::getName() const{
	return this->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::setGrade(int grade){
	if(grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if(grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade(){
	if(this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade(){
	if(this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::executeForm(AForm const &form) const{
	if (form.getSigned() == false)
		throw AForm::FormNotSignedException();
	if (this->getGrade() > form.getGradeToExec())
		throw AForm::GradeTooLowException();
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
	form.execute(*this);
}

void Bureaucrat::signForm(AForm &form) const{
	try
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << getName() << " couldn’t sign " << form.getName() << " because " << e.what() << "." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
