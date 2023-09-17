#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main ( void ) {
	ClapTrap a( "Henrique" );
	ScavTrap b( "Gabriel" );
	FragTrap c( "Miguel" );

	a.attack("Tests");
	b.attack("Shadow");
	c.attack("Wind");

	b.guardGate();
	b.guardGate();
	c.highFiveGuys();
}