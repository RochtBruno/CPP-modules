#include "FragTrap.hpp"

FragTrap::FragTrap():
        ClapTrap()
{
        this->_hit_points = 100;
        this->_energy_points = 100;
        this->_attack_damage = 30;
        std::cout << "FragTrap: { Default Constructor Called }" << std::endl;
}

FragTrap::FragTrap(const std::string &name):
                        ClapTrap(name)
{
        this->_hit_points = 100;
        this->_energy_points = 100;
        this->_attack_damage = 30;
        std::cout << "# FragTrap "  << this->_name << " is born! #" << std::endl;
}

FragTrap::~FragTrap()
{
        std::cout << "FragTrap: { Default Destructor Called }" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other):
                        ClapTrap(other)
{
        std::cout << "FragTrap: { Copy Constructor Called }" << std::endl;
        *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
        std::cout << "{ Copy Assignment Operator Called }" << std::endl;

        if (this != &other)
                ClapTrap::operator=(other); //| Operador de atribuição herdado, faz o mesmo papel.
        return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << ", its high fives time!" << std::endl;
}