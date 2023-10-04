#include "ClapTrap.hpp"

int main ( void ) {
	ClapTrap();
	ClapTrap a("Gabriel");
	
	for (int i = 0; i < 15; i++)
	{
		std::cout << i + 1 << ".";
		a.attack("Henrique");
	}
	a.beRepaired(2);
	a.beRepaired(3);
	a.beRepaired(4); // out of energy
}