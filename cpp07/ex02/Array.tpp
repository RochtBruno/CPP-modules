# include "Array.hpp"

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]), _size(n){}

template <typename T>
Array<T>::Array(const Array &other) : _elements(NULL), _size(0){
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other){
	if(this == &other)
		return *this;
	delete[] this->_elements;

	this->_size = other._size;
	this->_elements = new T[this->_size];

	for(unsigned int i = 0; i < this->_size; i++){
		this->_elements[i] = other._elements[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array(){
	if(this->_elements)
		delete[] this->_elements;
}

template <typename T>
T &Array<T>::operator[](unsigned int index){
	if (this->_size == 0)
		throw EmptyArray();
	if (index >= this->_size)
		throw OutOfBonds();
	return this->_elements[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const{
	if (this->_size == 0)
		throw EmptyArray();
	if (index >= this->_size)
		throw OutOfBonds();
	return this->_elements[index];
}

template <typename T>
int Array<T>::size(void) const{
	return this->_size;
}