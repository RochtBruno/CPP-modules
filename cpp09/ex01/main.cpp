#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return 1;
	}

	RPN calculator;

	try {
		calculator.process(argv[1]);
		std::cout << calculator.getResult() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
