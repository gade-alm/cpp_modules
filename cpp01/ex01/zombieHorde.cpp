#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombies = new Zombie[N];
	int i = -1;

	while (++i < N) {
		zombies[i].set_name(name);
		zombies[i].announce();
	}
	return zombies;
}