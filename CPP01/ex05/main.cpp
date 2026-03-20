#include "Harl.hpp"

int main(void)
{
	Harl harl;
	std::cout << "DEBUG test" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "INFO test" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	std::cout << "WARNING test" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << "ERROR test" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	std::cout << "Wrong test" << std::endl;
	harl.complain("TEST");
	std::cout << std::endl;
	std::cout << "Empty test" << std::endl;
	harl.complain("");
	std::cout << std::endl;
	return 0;
}
