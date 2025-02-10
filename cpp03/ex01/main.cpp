#include "ClapTrap.hpp"
#include "Scavtrap.hpp"

int	main(void)
{
	std::cout << "! Tests !" << std::endl;
	std::cout << "\n______________| Testing ClapTrap |______________" << std::endl;

	ClapTrap clap("Junin");
	clap.attack("Dragão de komodo");
	clap.takeDamage(5);
	clap.beRepaired(4);
	clap.takeDamage(3);
	clap.beRepaired(2);

	std::cout << "\n______________| Testing ScavTrap |______________" << std::endl;

	ScavTrap scav("Flavin");
	scav.attack("Tigre de bengala");
	scav.takeDamage(50);
	scav.beRepaired(40);
	scav.takeDamage(30);
	scav.beRepaired(20);

	std::cout << "\n______________| Testing Copy |____________" << std::endl;

	ScavTrap copy(scav);
	copy.attack("*Dummy01*");

	std::cout << "\n______________| Testing Assignment |______________" << std::endl;

	ScavTrap assignment = scav;
	assignment.attack("*Dummy02*");


	std::cout << "\n______________| Testing Destructors |______________" << std::endl;

	return (0);
}
