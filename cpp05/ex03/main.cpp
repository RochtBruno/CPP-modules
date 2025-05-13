#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    try {
        // Teste 1: Criar um Bureaucrat válido
        std::cout << "\nTeste 1: Criar um Bureaucrat válido" << std::endl;
        Bureaucrat bureaucrat("Alice", 1);
        std::cout << bureaucrat << std::endl;

        // Teste 2: Incrementar e decrementar o grade de um Bureaucrat
        std::cout << "\nTeste 2: Incrementar e decrementar o grade de um Bureaucrat" << std::endl;
        try {
            bureaucrat.incrementGrade();
            std::cout << "Após incremento: " << bureaucrat << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Erro ao incrementar: " << e.what() << std::endl;
        }
        try {
            bureaucrat.decrementGrade();
            std::cout << "Após decremento: " << bureaucrat << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Erro ao decrementar: " << e.what() << std::endl;
        }

        // Teste 3: Criar e executar ShrubberyCreationForm
        std::cout << "\nTeste 3: Criar e executar ShrubberyCreationForm" << std::endl;
        ShrubberyCreationForm shrubbery("Garden");
        std::cout << shrubbery << std::endl;
        shrubbery.beSigned(bureaucrat);
        shrubbery.execute(bureaucrat);

        // Teste 4: Criar e executar RobotomyRequestForm
        std::cout << "\nTeste 4: Criar e executar RobotomyRequestForm" << std::endl;
        RobotomyRequestForm robotomy("Target A");
        std::cout << robotomy << std::endl;
        robotomy.beSigned(bureaucrat);
        robotomy.execute(bureaucrat);

        // Teste 5: Criar e executar PresidentialPardonForm
        std::cout << "\nTeste 5: Criar e executar PresidentialPardonForm" << std::endl;
        PresidentialPardonForm pardon("Target B");
        std::cout << pardon << std::endl;
        pardon.beSigned(bureaucrat);
        pardon.execute(bureaucrat);

        // Teste 6: Criar um Intern e gerar formulários
        std::cout << "\nTeste 6: Criar um Intern e gerar formulários" << std::endl;
        Intern intern;
        AForm *form1 = intern.makeForm("shrubbery creation", "Home");
        AForm *form2 = intern.makeForm("robotomy request", "Robot");
        AForm *form3 = intern.makeForm("presidential pardon", "Citizen");

        std::cout << *form1 << std::endl;
        std::cout << *form2 << std::endl;
        std::cout << *form3 << std::endl;

        form1->beSigned(bureaucrat);
        form1->execute(bureaucrat);

        form2->beSigned(bureaucrat);
        form2->execute(bureaucrat);

        form3->beSigned(bureaucrat);
        form3->execute(bureaucrat);

        delete form1;
        delete form2;
        delete form3;

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    // Teste 7: Tentativa de criar um formulário inválido com Intern
    try {
        std::cout << "\nTeste 7: Tentativa de criar um formulário inválido com Intern" << std::endl;
        Intern intern;
        AForm *invalidForm = intern.makeForm("invalid form", "Nowhere");
        delete invalidForm;
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    // Teste 8: Tentativa de execução sem assinatura
    try {
        std::cout << "\nTeste 8: Tentativa de execução sem assinatura" << std::endl;
        ShrubberyCreationForm shrubbery("Forest");
        std::cout << shrubbery << std::endl;
        shrubbery.execute(Bureaucrat("Bob", 50));
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    // Teste 9: Tentativa de execução com Bureaucrat de grade insuficiente
    try {
        std::cout << "\nTeste 9: Tentativa de execução com Bureaucrat de grade insuficiente" << std::endl;
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
