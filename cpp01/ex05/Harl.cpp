#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Harl constructor" << std::endl;
}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money.You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	for(size_t i = 0; i < level.length();i++){
		level[i] = tolower(level[i]);
	}
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"debug", "info", "warning", "error"};

	for(int i = 0; i < 4; i++){
		if(level == levels[i]){
			(this->*ptr[i])();
			return;
		}
	}
}


Harl::~Harl() {
	std::cout << "Harl destructor" << std::endl;
}
