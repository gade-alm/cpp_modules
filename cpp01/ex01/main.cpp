#include "Zombie.hpp"

int main(void)
{
	Zombie *zombies = zombieHorde(10, "Gabriel");

	delete[] zombies;
}
