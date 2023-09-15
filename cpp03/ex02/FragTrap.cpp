#include "FragTrap.hpp"

FragTrap::FragTrap() {
	_name = "";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap Constructor Called" << std::endl;
}
 
FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor Called" << std::endl;
}

FragTrap::FragTrap( std::string name ) {

}

FragTrap::FragTrap( const FragTrap& obj ) : ClapTrap() {

}

FragTrap& FragTrap::operator=( const FragTrap& obj ) { 

}

void	FragTrap::highFiveGuys( void ) {
	std::cout << "FragTrap " << _name << "High Fived his friends" << std::endl;
}