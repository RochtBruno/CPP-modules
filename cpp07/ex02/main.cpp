# include "Array.hpp"

int main(void)
{
	std::cout << "=== Teste de criação de arrays vazios ===" << std::endl;
	Array<int> emptyArray;
	try
	{
		std::cout << "Tamanho do array vazio: " << emptyArray.size() << std::endl;
		emptyArray[0] = 42;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Teste de criação de arrays com tamanho específico ===" << std::endl;
	Array<int> intArray(5);
	for (int i = 0; i < 5; i++)
		intArray[i] = i * 10;
	for (int i = 0; i < 5; i++)
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

	std::cout << "\n=== Teste de acesso fora dos limites ===" << std::endl;
	try
	{
		std::cout << intArray[10] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Teste de cópia de arrays ===" << std::endl;
	Array<int> copiedArray(intArray);
	for (int i = 0; i < copiedArray.size(); i++)
		std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;

	std::cout << "\n=== Teste de atribuição de arrays ===" << std::endl;
	Array<int> assignedArray;
	assignedArray = intArray;
	for (int i = 0; i < assignedArray.size(); i++)
		std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;

	std::cout << "\n=== Teste com tipos diferentes ===" << std::endl;
	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";
	for (int i = 0; i < stringArray.size(); i++)
		std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;

	std::cout << "\n=== Teste de destruição ===" << std::endl;
	{
		Array<double> tempArray(3);
		tempArray[0] = 1.1;
		tempArray[1] = 2.2;
		tempArray[2] = 3.3;
		for (int i = 0; i < tempArray.size(); i++)
			std::cout << "tempArray[" << i << "] = " << tempArray[i] << std::endl;
	} 

	return (0);
}