#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

int	main(void)
{
	int n = 10;
	int half = n / 2;

	AAnimal *animals[n];
	Brain brain;


	for (int i = 0; i < half ; i++)
		animals[i] = new Cat();
	for (int i = half; i < n; i++)
		animals[i] = new Dog();

	std::cout << std::endl;

	Cat *cat = new Cat();
	Cat *newCat = new Cat(*cat);
	//std::cout << brain.getIdeas();
	delete cat;
	delete newCat;

	std::cout << std::endl;

	for (int i = 0; i < n; i++)
		delete animals[i];

	return (0);
}
