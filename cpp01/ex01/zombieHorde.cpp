#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0 || N > 214748347){
		std::cout << "Number on wrong scope" << std::endl;
		return 0;
	}
	
	Zombie* zombies = new Zombie[N];
	int i = -1;

	while (++i < N) {
		zombies[i].set_name(name);
		zombies[i].announce();
	}
	return zombies;
}