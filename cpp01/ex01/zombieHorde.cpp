#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombies = new Zombie[5];

	for (int i = 0; i < N; i++)
	{
		zombies->set_name(name);
		zombies->announce();
	}
	return zombies;
}