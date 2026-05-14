#include "Serializer.hpp"

int main()
{
	Data data;
	data.i = 10;
	data.test = "test";
	std::cout << "Original pointer: " << &data << std::endl;
	
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized: " << raw << std::endl;
	
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized: " << ptr << std::endl;

	if (ptr == &data)
		std::cout << "Succes: pointers match" << std::endl;
	else
		std::cout << "Failure: pointers do not match" << std::endl;
}
