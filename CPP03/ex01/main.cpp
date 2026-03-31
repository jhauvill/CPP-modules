#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap p("poto");
	p.attack("pelo");
	p.beRepaired(20);
	p.takeDamage(20);
	p.guardGate();
	ScavTrap e = p;
	e.attack("chef");
	ScavTrap z("zebi");
	z.attack("poto");
	z = p;
	z.attack("pelo");
	return 0;
}