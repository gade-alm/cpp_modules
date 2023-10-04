#include "Zombie.hpp"

int main( void )
{
	Zombie *zombies = zombieHorde(5, "Gabriel");

	delete[] zombies;
}
