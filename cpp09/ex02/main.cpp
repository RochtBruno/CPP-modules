#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error: Not enough arguments" << std::endl;
		return 1;
	}

	PmergeMe sorter;
	std::set<int> uniqueNumbers;

	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		for (std::string::size_type j = 0; j < arg.size(); ++j) {
			if (!isdigit(arg[j])) {
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}
		int num = std::atoi(argv[i]);
		if (num <= 0) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
		if (uniqueNumbers.find(num) != uniqueNumbers.end()) {
			std::cerr << "Error: Duplicate number " << num << std::endl;
			return 1;
		}
		uniqueNumbers.insert(num);
		sorter.addNumber(num);
	}

	sorter.sortAndPrint();

	return 0;
}
