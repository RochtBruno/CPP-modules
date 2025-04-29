#include "Bureaucrat.hpp"

int main()
{

	std::cout << "Teste 1: Criação de um Bureaucrat válido" << std::endl;
	try {
		Bureaucrat bureaucrat1("Alice", 50);
		std::cout << bureaucrat1 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro ao criar Bureaucrat: " << e.what() << std::endl;
	}

	std::cout << "\nTeste 2: Tentativa de criar um Bureaucrat com grade muito alto" << std::endl;
	try {
		Bureaucrat bureaucrat2("Bob", 0);
		std::cout << bureaucrat2 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro ao criar Bureaucrat: " << e.what() << std::endl;
	}


	std::cout << "\nTeste 3: Tentativa de criar um Bureaucrat com grade muito baixo" << std::endl;
	try {
		Bureaucrat bureaucrat3("Charlie", 200);
		std::cout << bureaucrat3 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro ao criar Bureaucrat: " << e.what() << std::endl;
	}


	std::cout << "\nTeste 4: Incremento de grade" << std::endl;
	try {
		Bureaucrat bureaucrat4("Diana", 1);
		std::cout << "Antes do incremento: " << bureaucrat4 << std::endl;
		bureaucrat4.decrementGrade();
		std::cout << "Depois do incremento: " << bureaucrat4 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro ao incrementar grade: " << e.what() << std::endl;
	}

	std::cout << "\nTeste 5: Decremento de grade" << std::endl;
	try {
		Bureaucrat bureaucrat5("Eve", 150);
		std::cout << "Antes do decremento: " << bureaucrat5 << std::endl;
		bureaucrat5.incrementGrade();
		std::cout << "Depois do decremento: " << bureaucrat5 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro ao decrementar grade: " << e.what() << std::endl;
	}


	std::cout << "\nTeste 6: Incremento que ultrapassa o limite superior" << std::endl;
	try {
		Bureaucrat bureaucrat6("Frank", 1);
		std::cout << "Antes do incremento: " << bureaucrat6 << std::endl;
		bureaucrat6.incrementGrade();
		std::cout << "Depois do incremento: " << bureaucrat6 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro ao incrementar grade: " << e.what() << std::endl;
	}


	std::cout << "\nTeste 7: Decremento que ultrapassa o limite inferior" << std::endl;
	try {
		Bureaucrat bureaucrat7("Grace", 150);
		std::cout << "Antes do decremento: " << bureaucrat7 << std::endl;
		bureaucrat7.decrementGrade();
		std::cout << "Depois do decremento: " << bureaucrat7 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro ao decrementar grade: " << e.what() << std::endl;
	}

	return 0;
}
