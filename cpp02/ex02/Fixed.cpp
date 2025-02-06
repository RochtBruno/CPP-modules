#include "Fixed.hpp"

Fixed::Fixed(): _value(0){
	std::cout << "Default construtor method called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed){
	std::cout << "Copy constructor method called" << std::endl;
	*this = fixed;
}

int		Fixed::getRawBits(void) const{
	return this->_bits;
}

void	Fixed::setRawBits(int const raw){
	this->_value = raw;
}

int		Fixed::toInt(void) const{
	return (this->_value >> this->_bits);
}

float	Fixed::toFloat(void) const {
	return ((float)this->_value / (1 << this->_bits));
}

Fixed &Fixed::operator=(const Fixed &other){
	if(this == &other){
		return *this;
	}
	this->_value = other.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed &fixed) const{
	if(this->_value > fixed.getRawBits()){
		return true;
	}
	return false;
}

bool	Fixed::operator>=(const Fixed &fixed) const {
	if(this->_value >= fixed.getRawBits()){
		return true;
	}
	return false;
}

bool	Fixed::operator<(const Fixed &fixed) const {
	if(this->_value < fixed.getRawBits()){
		return true;
	}
	return false;
}

bool	Fixed::operator<=(const Fixed &fixed) const {
	if(this->_value <= fixed.getRawBits()){
		return true;
	}
	return false;
}

bool	Fixed::operator!=(const Fixed &fixed) const {
	if(this->_value == fixed.getRawBits()){
		return true;
	}
	return false;
}

bool	Fixed::operator==(const Fixed &fixed) const {
	if(this->_value == fixed.getRawBits()){
		return true;
	}
	return false;
}

Fixed	Fixed::operator+(const Fixed &fixed) const{
	return(Fixed(this->toFloat() + fixed.toFloat()));
};

Fixed	Fixed::operator-(const Fixed &fixed) const{
	return(Fixed(this->toFloat() - fixed.toFloat()));
};

Fixed	Fixed::operator*(const Fixed &fixed) const{
	return(Fixed(this->toFloat() * fixed.toFloat()));
};

Fixed	Fixed::operator/(const Fixed &fixed) const{
	return (Fixed(this->toFloat() / fixed.toFloat()));
};

Fixed::~Fixed(){
	std::cout << "Destructor method called" << std::endl;
}
