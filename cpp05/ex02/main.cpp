#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try {
        // Teste 1: Criar um Bureaucrat válido
        Bureaucrat bureaucrat("Alice", 1);
        std::cout << bureaucrat << std::endl;

        // Teste 2: Criar e executar ShrubberyCreationForm
        std::cout << "\nTeste 2: ShrubberyCreationForm" << std::endl;
        ShrubberyCreationForm shrubbery("Garden");
        std::cout << shrubbery << std::endl;
        shrubbery.beSigned(bureaucrat);
        shrubbery.execute(bureaucrat);

        // Teste 3: Criar e executar RobotomyRequestForm
        std::cout << "\nTeste 3: RobotomyRequestForm" << std::endl;
        RobotomyRequestForm robotomy("Target A");
        std::cout << robotomy << std::endl;
        robotomy.beSigned(bureaucrat);
        robotomy.execute(bureaucrat);

        // Teste 4: Criar e executar PresidentialPardonForm
        std::cout << "\nTeste 4: PresidentialPardonForm" << std::endl;
        PresidentialPardonForm pardon("Target B");
        std::cout << pardon << std::endl;
        pardon.beSigned(bureaucrat);
        pardon.execute(bureaucrat);

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    // Teste 5: Tentativa de execução sem assinatura
    try {
        std::cout << "\nTeste 5: Tentativa de execução sem assinatura" << std::endl;
        ShrubberyCreationForm shrubbery("Forest");
        std::cout << shrubbery << std::endl;
        shrubbery.execute(Bureaucrat("Bob", 50));
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    // Teste 6: Tentativa de execução com Bureaucrat de grade insuficiente
    try {
        std::cout << "\nTeste 6: Tentativa de execução com Bureaucrat de grade insuficiente" << std::endl;
        Bureaucrat lowRank("Charlie", 150);
        PresidentialPardonForm pardon("Target C");
        std::cout << pardon << std::endl;
        pardon.beSigned(lowRank);
        pardon.execute(lowRank);
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
