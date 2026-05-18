#include "iter.hpp"

void increment(int &i)
{
	i++;
}

void print_int(const int &i)
{
	std::cout << i << std::endl;
}

void print(const std::string &str)
{
	std::cout << str << std::endl;
}

int main(void)
{
	int array[4] = {0, 1, 2, 3};
	const std::string str_array[4] = {"a", "b", "c", "d"};

	iter(array, 4, increment);
	iter(array, 4, print_int);

	std::cout << "\n";

	iter(str_array, 4, print);

	return 0;
}
