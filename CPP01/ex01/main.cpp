#include "Zombie.hpp"

int main()
{
	int N = 9;
	Zombie* z = zombieHorde(N, "chef");

	for (int i = 0; i < N; i++)
		z[i].announce();
	delete[] z;
	return 0;
}