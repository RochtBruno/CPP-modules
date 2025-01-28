#include "FileHandler.hpp"
#include <string>
#include <iostream>
#include <ostream>

int main(int argc, char* argv[]) {
	// Verificar o número de argumentos
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	// Obter os argumentos
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// Verificar se s1 não está vazio
	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}

	// Criar o objeto FileHandler e realizar a substituição
	FileHandler fileHandler(filename, s1, s2);
	if (!fileHandler.replaceAndSave()) {
		return 1;
	}

	std::cout << "File successfully processed. Output saved to " << filename + ".replace" << std::endl;

	return 0;
}
