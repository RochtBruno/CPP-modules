#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array{
	private:
		T				*_elements;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T	&operator[](unsigned int index);
		const T	&operator[](unsigned int index) const;

		int	size(void) const;

		class EmptyArray : public std::exception{
			public:
				virtual const char *what() const throw(){
					return("Error: there is no elements in the array!");
				};
		};

		class OutOfBonds : public std::exception{
			public:
				virtual const char *what() const  throw(){
					return("Error: index selected were out of bond!");
				};
		};
};

#include "Array.tpp"
