#include "ScavTrap.hpp"

int main ( void ) {
	ClapTrap a("Henrique");
	a.attack("");
	a.attack("Joao");

	ScavTrap b("Gabriel");
	b.attack ("Henrique");

	b.guardGate();
	b.guardGate();
}