#include "Zombie.hpp"

//passado por referencia para evitar copia desnecessaria, usando lista de inicializacao
Zombie::Zombie(const std::string &zName) : _name(zName){};

Zombie::~Zombie(){
	std::cout << _name << " is dead" << std::endl;
}

void Zombie::announce(void){
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

