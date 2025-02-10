#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hit_points(10),_energy_points(10), _attack_damage(10){
	std::cout << "Default construtor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hit_points(10),_energy_points(10), _attack_damage(10){
	std::cout << this->_name << " was created." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	std::cout << "Assigment operator called" << std::endl;
	if(this == &other){
		return *this;
	}
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;

	return *this;
}

ClapTrap::ClapTrap(const ClapTrap &other){
	std::cout << "Copy constructor called" << std::endl;	
	*this = other;
}

ClapTrap::~ClapTrap(){
	std::cout << "Default destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target){
	if(this->_energy_points < 1)
		std::cout << this->_name << " has not enough energy points to attack" << std::endl;
	else if(this->_hit_points < 1)
		std::cout << this->_name << " has not enough hit points to attack" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " , causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	if(this->_hit_points < 1)
		std::cout << this->_name << " is already dead" << std::endl;
	else{
		std::cout << "Claptrap" << this->_name << " has taken " << amount << " of damage" << std::endl;
		if (this->_hit_points < amount)
			this->_hit_points = 0;
		else
			this->_hit_points -= amount;
	}
};

void	ClapTrap::beRepaired(unsigned int amount){
	if(this->_energy_points < 1)
		std::cout << this->_name << " has not enought energy points to be repaired" << std::endl;
	else if(this->_hit_points < 1)
		std::cout << this->_name << " is already dead." << std::endl;
	else{
		std::cout << "ClapTrap" << this->_name << " is being repaired with " << amount << " of points" << std::endl;
		if(this->_hit_points + amount > 10)
			this->_hit_points = 10;
		else
			this->_hit_points++;
	}
}