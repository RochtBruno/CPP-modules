#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();

    std::string newFileName = this->_target + "_shrubbery";
    std::ofstream newFile;

    newFile.open(newFileName.c_str(), std::ofstream::out);
    if (!newFile.is_open())
    {
        throw ShrubberyCreationForm::OpenFileException();
    }
    newFile << "       ccee88oo          " << std::endl;
    newFile << "  C8O8O8Q8PoOb o8oo      " << std::endl;
    newFile << " dOB69QO8PdUOpugoO9bD    " << std::endl;
    newFile << "CgggbU8OU qOp qOdoUOdcb  " << std::endl;
    newFile << "    6OuU  /p u gcoUodpP  " << std::endl;
    newFile << "      \\\\//  /douUP       " << std::endl;
    newFile << "        \\\\////           " << std::endl;
    newFile << "         |||/\\           " << std::endl;
    newFile << "         |||\\/           " << std::endl;
    newFile << "         |||||            " << std::endl;
    newFile << "   .....//||||\\....       " << std::endl;
    newFile.close();
}


const char * ShrubberyCreationForm::OpenFileException::what() const throw()
{
    return ("Could not create the new file.");
}
