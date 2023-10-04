#include "Zombie.hpp"

int main( void )
{
	Zombie *zombie;

	zombie = newZombie("Gabriel");
	randomChump("Zombie");
	delete (zombie);
}