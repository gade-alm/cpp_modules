#include "Zombie.hpp"

int main(void)
{
	Zombie *zumbi;

	zumbi = newZombie("Gabriel");
	randomChump("Zumbi");
	delete (zumbi);
}