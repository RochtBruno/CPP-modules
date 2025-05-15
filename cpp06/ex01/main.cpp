# include "Serializer.hpp"

int main()
{
	Data data;
	data.i = 42;
	data.f = 3.14f;
	data.c = 'a';

	std::cout << "Original Data:" << std::endl;
	std::cout << "i: " << data.i << ", f: " << data.f << ", c: " << data.c << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;

	Data *deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "i: " << deserializedData->i << ", f: " << deserializedData->f << ", c: " << deserializedData->c << std::endl;

	return 0;
}
