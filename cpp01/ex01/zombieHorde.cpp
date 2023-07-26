#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name )
{
	Zombie *zombies;

	for (int i = 0; i < N; i++)
	{
		zombies[i] = newZombie(name);
	}
	for (int i = N; i > 0; i--)
	{
		delete (zombies[i]);
	}
}