#include "Zombie.hpp"

Zombie::Zombie(std::string zName) : name(zName){};

Zombie::~Zombie(){
	std::cout << name << " is dead" << std::endl;
}

void Zombie::announce(void){
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

