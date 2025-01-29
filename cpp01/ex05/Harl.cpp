#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Harl constructor" << std::endl;
}

void Harl::debug(void) {
	std::cout << "Debug: This is a debug message" << std::endl;
}

void Harl::info(void) {
	std::cout << "Info: This is an info message" << std::endl;
}

void Harl::warning(void) {
	std::cout << "Warning: This is a warning message" << std::endl;
}

void Harl::error(void) {
	std::cout << "Error: This is an error message" << std::endl;
}

void Harl::complain(std::string level) {
	
}


Harl::~Harl() {
	std::cout << "Harl destructor" << std::endl;
}
