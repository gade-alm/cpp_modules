#include "ClapTrap.hpp"

int main ( void ) {
	ClapTrap();
	ClapTrap a("Gabriel");
	
	for (int i = 0; i < 8; i++)
	{
		std::cout << i + 1 << ". ";
		a.attack("Henrique");
	}
	a.beRepaired(2);
	a.beRepaired(30);
	a.beRepaired(4); // out of energy
	a.beRepaired(10);
	a.attack("Dummy");
}