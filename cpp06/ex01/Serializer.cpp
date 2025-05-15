# include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	std::cout << "Serializer copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// não tem nenhum atributo para copiar
	}
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	std::cout << "Serializer serialize called" << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	std::cout << "Serializer deserialize called" << std::endl;
	return reinterpret_cast<Data *>(raw);
}


