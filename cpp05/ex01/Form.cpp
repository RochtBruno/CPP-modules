#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("default"), _signed(false), _grade_required(150), _grade_to_exec(150)
{
	std::cout << "Form default constructor called" << std::endl;
}
Form::Form(const std::string &name, int grade_required, int grade_to_exec) : _name(name), _signed(false), _grade_required(grade_required), _grade_to_exec(grade_to_exec)
{
	std::cout << "Form parameterized constructor called" << std::endl;
	if (grade_required < 1 || grade_to_exec < 1)
		throw Form::GradeTooHighException();
	if (grade_required > 150 || grade_to_exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _grade_required(other._grade_required), _grade_to_exec(other._grade_to_exec)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName(void) const
{
	return this->_name;
}

int Form::getSigned() const
{
	return this->_signed;
}
int Form::getGradeRequired() const
{
	return this->_grade_required;
}
int Form::getGradeToExec() const 
{
	return this->_grade_to_exec;
}
void Form::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() > this->_grade_required)
		throw Form::GradeTooLowException();
	this->_signed = true;
	std::cout << other.getName() << " signed " << this->_name << std::endl;
}
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << "Form name: " << form.getName() << std::endl;
	os << "Form signed: " << form.getSigned() << std::endl;
	os << "Form grade required: " << form.getGradeRequired() << std::endl;
	os << "Form grade to exec: " << form.getGradeToExec() << std::endl;
	return os;
}
