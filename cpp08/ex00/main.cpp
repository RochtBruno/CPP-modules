# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include "easyfind.hpp"

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::cout << "\n=== Testando vector ===" << std::endl;
	std::cout << "Procurando 2 (existente): ";
	bool found = easyfind(vec, 2);
	std::cout << "Retorno da função: " << (found ? "true" : "false") << std::endl;

	std::cout << "\nProcurando 5 (inexistente): ";
	found = easyfind(vec, 5);
	std::cout << "Retorno da função: " << (found ? "true" : "false") << std::endl;

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	std::cout << "\n=== Testando list ===" << std::endl;
	std::cout << "Procurando 20 (existente): ";
	found = easyfind(lst, 20);
	std::cout << "Retorno da função: " << (found ? "true" : "false") << std::endl;

	std::cout << "\nProcurando 40 (inexistente): ";
	found = easyfind(lst, 40);
	std::cout << "Retorno da função: " << (found ? "true" : "false") << std::endl;

	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	std::cout << "\n=== Testando deque ===" << std::endl;
	std::cout << "Procurando 200 (existente): ";
	found = easyfind(deq, 200);
	std::cout << "Retorno da função: " << (found ? "true" : "false") << std::endl;


	std::cout << "\nProcurando 500 (inexistente): ";
	found = easyfind(deq, 500);
	std::cout << "Retorno da função: " << (found ? "true" : "false") << std::endl;

	std::vector<int> empty_vec;

	std::cout << "\n=== Testando vector vazio ===" << std::endl;
	std::cout << "Procurando 1 (em container vazio): ";
	found = easyfind(empty_vec, 1);
	std::cout << "Retorno da função: " << (found ? "true" : "false") << std::endl;

	return 0;
}
