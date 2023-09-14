#include "ScavTrap.hpp"

int main ( void ) {
	ClapTrap();
	ClapTrap a("Henrique");
	
	for (int i = 0; i < 8; i++)
	{
		std::cout << i + 1 << ".";
		a.attack("");
	}
	a.beRepaired(2);
	a.beRepaired(3);
	a.beRepaired(4);
	ScavTrap b("Gabriel");
	
}