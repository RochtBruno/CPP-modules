#include "Zombie.hpp"

int main(void){
	Zombie firstZombie = Zombie("firstZombie");

	firstZombie.announce();

	Zombie *secondZombie = newZombie("secondZombie");

	delete secondZombie;

	randomChump("thirdZombie");

	return 0;
}