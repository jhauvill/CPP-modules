#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	std::string string_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = -1;
	if (ac != 2)
		return 1;
	for (int i = 0; i < 4; i++)
		if (av[1] == string_tab[i])
			index = i;
	switch (index)
	{
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
	}
	return 0;
}