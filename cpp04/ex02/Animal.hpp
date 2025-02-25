#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal(const std::string &type);
		virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &other);

		virtual void	makeSound() const = 0; // Agora a classe é abstrata
		std::string		getType(void) const;
};

#endif
