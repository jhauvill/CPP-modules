#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap p("poto");
	p.attack("pelo");
	p.beRepaired(20);
	p.takeDamage(20);
	p.highFivesGuys();
	FragTrap e = p;
	e.attack("chef");
	FragTrap z("zebi");
	z.attack("poto");
	z = p;
	z.attack("pelo");
	return 0;
}