#include "Array.hpp"

int main(void)
{
	Array<int> intArray;
	Array<unsigned int> uintArray(4);

	for (unsigned int i = 0; i < uintArray.size(); i++)
		uintArray[i] = 2;

	try
	{
		std::cout << uintArray[6] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << uintArray[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		intArray[0] = 20;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Array<unsigned int> cpArray(uintArray);
	try
	{
		cpArray[2] = 23;
		std::cout << "Original array " << uintArray[2] << std::endl;
		std::cout << "Copy array " << cpArray[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Array<unsigned int> cpArray2;
	cpArray2 = uintArray;
	try
	{
		cpArray2[2] = 45;
		std::cout << "Original array " << uintArray[2] << std::endl;
		std::cout << "Copy array " << cpArray2[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
