#pragma once

#include <algorithm>
#include <stdexcept>
#include <iterator>

template <typename T>
bool easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()){
		std::cout << "Value not found" << std::endl;
		return false;
	}
	std::cout << "Value found: " << *it << std::endl;
	return true	;
}
