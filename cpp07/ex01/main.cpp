#include "iter.hpp"

int main() {
	int array[] = {1, 2, 3, 4, 5};
	std::string strArray[] = {"banana", "roma", "carro monstro", "kk"};

	btaveira::iter(array, 5, btaveira::printElement);
	std::cout << std::endl;
	btaveira::iter(strArray, 3, btaveira::printElement);
	std::cout << std::endl;

	return 0;
}
