#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _grade_required(150), _grade_to_exec(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}
AForm::AForm(const std::string &name, int grade_required, int grade_to_exec) : _name(name), _signed(false), _grade_required(grade_required), _grade_to_exec(grade_to_exec)
{
	std::cout << "AForm parameterized constructor called" << std::endl;
	if (grade_required < 1 || grade_to_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_required > 150 || grade_to_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _grade_required(other._grade_required), _grade_to_exec(other._grade_to_exec)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName(void) const
{
	return this->_name;
}

int AForm::getSigned() const
{
	return this->_signed;
}
int AForm::getGradeRequired() const
{
	return this->_grade_required;
}
int AForm::getGradeToExec() const
{
	return this->_grade_to_exec;
}
void AForm::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() > this->_grade_required)
		throw AForm::GradeTooLowException();
	this->_signed = true;
	std::cout << other.getName() << " signed " << this->_name << std::endl;
}
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
std::ostream &operator<<(std::ostream &os, AForm const &Aform)
{
	os << "AForm name: " << Aform.getName() << std::endl;
	os << "AForm signed: " << Aform.getSigned() << std::endl;
	os << "AForm grade required: " << Aform.getGradeRequired() << std::endl;
	os << "AForm grade to exec: " << Aform.getGradeToExec() << std::endl;
	return os;
}
