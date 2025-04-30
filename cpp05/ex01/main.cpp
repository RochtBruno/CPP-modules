#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "Teste 1: Criação de um Form válido" << std::endl;
	try {
		Form form1("Form A", 50, 25);
		std::cout << form1 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro ao criar Form: " << e.what() << std::endl;
	}

	std::cout << "\nTeste 2: Tentativa de criar um Form com grade de assinatura muito alta" << std::endl;
	try {
		Form form2("Form B", 0, 25);
		std::cout << form2 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro ao criar Form: " << e.what() << std::endl;
	}

	std::cout << "\nTeste 3: Tentativa de criar um Form com grade de execução muito baixa" << std::endl;
	try {
		Form form3("Form C", 50, 200);
		std::cout << form3 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro ao criar Form: " << e.what() << std::endl;
	}

	std::cout << "\nTeste 4: Assinatura de um Form por um Bureaucrat válido" << std::endl;
	try {
		Bureaucrat bureaucrat("Alice", 30);
		Form form4("Form D", 50, 25);
		std::cout << "Antes da assinatura: " << form4 << std::endl;
		form4.beSigned(bureaucrat);
		std::cout << "Depois da assinatura: " << form4 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro ao assinar Form: " << e.what() << std::endl;
	}

	std::cout << "\nTeste 5: Tentativa de assinatura com Bureaucrat de grade insuficiente" << std::endl;
	try {
		Bureaucrat bureaucrat("Bob", 100);
		Form form5("Form E", 50, 25);
		std::cout << "Antes da assinatura: " << form5 << std::endl;
		form5.beSigned(bureaucrat);
		std::cout << "Depois da assinatura: " << form5 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro ao assinar Form: " << e.what() << std::endl;
	}

	return 0;
}