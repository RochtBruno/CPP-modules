#include "Zombie.hpp"

int main(void){
	//zombie criado na stack, ele morre automaticamente quando o programa encerra
	Zombie firstZombie = Zombie("firstZombie");

	firstZombie.announce();
	//zombie criado na heap, ele morre quando deletado (mallocado)
	Zombie *secondZombie = newZombie("secondZombie");

	secondZombie->announce();
	//deletando o zombie da heap
	delete secondZombie;

	randomChump("thirdZombie");

	return 0;
}
