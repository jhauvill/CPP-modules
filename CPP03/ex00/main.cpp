#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("chef");
	ClapTrap b("pelo");
	a.attack("pelo");
	b.takeDamage(0);
	b.beRepaired(10);
	ClapTrap c = a;
	c.attack("nobody");
	return 0;
}