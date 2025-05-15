#pragma once
#include <iostream>

namespace btaveira{

	template <typename T>
	void printElement(T &element) {
		std::cout << "element-> " << element << " | ";
	}

	template <typename T>
	void iter(T *array, int length, void (*f)(T &)) {
		for (int i = 0; i < length; i++) {
			f(array[i]);
		}
	}

}

