#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "=== Creating DiamondTrap ===" << std::endl;
	DiamondTrap p("poto");
	DiamondTrap e = p;
	DiamondTrap z("zebi");
	z = p;
	std::cout << std::endl;
	std::cout << "=== Testing DiamondTrap ===" << std::endl;
	p.attack("pelo");
	p.beRepaired(20);
	p.takeDamage(20);
	p.highFivesGuys();
	e.attack("chef");
	z.attack("poto");
	z.attack("pelo");
	z.whoAmI();
	std::cout << std::endl;
	std::cout << "=== Destroying DiamondTrap ===" << std::endl;
	return 0;
}