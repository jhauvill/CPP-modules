#include <iostream>
#include <cstring>


int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int j = 1; j < ac; j++)
	{
		for (size_t i = 0; i < strlen(av[j]); i++)
		{
			av[j][i] = toupper(av[j][i]);
		}
		std::cout << av[j];
	}
	std::cout << std::endl;
	return 0;
}
