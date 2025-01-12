#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << this->_name << " created" << std::endl;
}

Zombie::Zombie(std::string name){
	_name = name;
}

Zombie::~Zombie(){
	std::cout << this->_name << " died" << std::endl;
}

void Zombie::announce(){
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
	_name = name;
}