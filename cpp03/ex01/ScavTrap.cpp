#include "Scavtrap.hpp"


ScavTrap::ScavTrap() : ClapTrap() {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "Default constructor called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "Default destructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap " << this->_name << " was created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	std::cout << "Operator assigment called" << std::endl;
	if(this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void	ScavTrap::attack(const std::string &target){
	if(this->_energy_points < 1)
		std::cout << "ScavTrap " << this->_name << " has not enough energy points to attack" << std::endl;
	else if(this->_hit_points < 1)
		std::cout << "ScavTrap " << this->_name << " has not enough hit points to attack" << std::endl;
	else{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points -= 1;
	}
}

void	ScavTrap::guardGate(){
	if(this->_hit_points < 1)
		std::cout << "ScavTrap " << this->_name << " has not enough hit points" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << "is now in Gate keeper mode!" << std::endl;
}




