#pragma once

#include <iostream>
# include <stdint.h>


typedef struct Data
{
	int		i;
	float	f;
	char	c;
} Data;

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
	public:
		static uintptr_t serialize(Data *ptr);
		//transforma o endereço do ponteiro em um número inteiro
		static struct Data *deserialize(uintptr_t raw);
		//transforma o número inteiro de volta em um ponteiro
};

