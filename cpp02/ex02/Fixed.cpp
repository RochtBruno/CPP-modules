#include "Fixed.hpp"

Fixed::Fixed(): _value(0){
	std::cout << "Default construtor method called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed){
	std::cout << "Copy constructor method called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int value){
	this->_value = value << this->_bits;
};

Fixed::Fixed(const float value){
	this->_value = roundf(value * (1 << this->_bits));
};

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
	if(this->_value != fixed.getRawBits()){
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

Fixed	Fixed::operator++(int){
	Fixed	tmp(*this); // cópia do objeto atual
	operator++(); //chama o operador para incrementar
	return (tmp); //retorna a cópia do objeto sem estar incrementada
}

Fixed	&Fixed::operator++(void){ // pré incremento deve modificar o próprio obj
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--(int){
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

Fixed	&Fixed::operator--(void){
	this->_value--;
	return (*this);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b){
	if(a < b)
		return a;
	return b;
}

const	Fixed	&Fixed::min(const Fixed &a, const Fixed &b){
	if(a < b)
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b){
	if(a > b)
		return a;
	return b;
}

const	Fixed	&Fixed::max(const Fixed &a, const Fixed &b){
	if(a > b)
		return a;
	return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
	out << fixed.toFloat();
	return out;
}

Fixed::~Fixed(){
	std::cout << "Destructor method called" << std::endl;
}
