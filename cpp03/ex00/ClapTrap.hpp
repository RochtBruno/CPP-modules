#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{

	private:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
	public:
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other); //construtor de cópia
		ClapTrap &operator=(const ClapTrap &other); //construtor de atribuição
		~ClapTrap();
};


#endif