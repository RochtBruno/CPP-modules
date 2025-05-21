#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) {
	_vec.reserve(n);
	std::cout << "Capacity of elements in this vector-> " << _vec.capacity() << std::endl;
}

Span::Span(const Span &other) {
	*this = other;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_vec = other._vec;
	}
	return *this;
}

Span::~Span() {}

void Span::displayElements(void) {
	std::cout << "Elements in the vector: " << std::endl;
	for (size_t i = 0; i < this->_vec.size(); i++)
		std::cout << this->_vec.at(i) << std::endl;
}

void Span::addNumber(unsigned int number) {
	if (_vec.size() >= _vec.capacity())
		throw OutOfLimit();
	_vec.push_back(number);
	std::cout << "Added number: " << number << std::endl;
	displayElements();
}

unsigned int Span::shortestSpan() {
	if (_vec.size() < 2)
		throw NoSpan();
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	unsigned int min = static_cast<unsigned int>(tmp[1] - tmp[0]);
	for (size_t i = 0; i < tmp.size() - 1; i++) {
		unsigned int diff = static_cast<unsigned int>(tmp[i + 1] - tmp[i]);
		if (diff < min)
			min = diff;
	}
	return min;
}

unsigned int Span::longestSpan() {
	if (_vec.size() < 2)
		throw NoSpan();
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}
