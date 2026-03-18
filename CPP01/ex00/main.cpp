#include "Zombie.hpp"

int main()
{
	Zombie* zombie2 = newZombie("poto");

	randomChump("pelo");
	zombie2->announce();
	delete zombie2;
	return (0);
}
