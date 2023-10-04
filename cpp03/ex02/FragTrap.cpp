#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {
	_name = "";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << RED << "FragTrap Constructor Called" << RESET << std::endl;
}
 
FragTrap::~FragTrap( void ) {
	std::cout << RED << "FragTrap Destructor Called" << RESET << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << RED << "FragTrap " << name << " Constructor Called" << RESET << std::endl;
}

FragTrap::FragTrap( const FragTrap& obj ) : ClapTrap() {
	std::cout << RED << "FragTrap Copy Constructor called" << RESET << std::endl;
	*this = obj;
}

FragTrap& FragTrap::operator=( const FragTrap& obj ) { 
	std::cout << RED << "FragTrap Assignemnt overload called" << RESET << std::endl;
	_name = obj._name;
	_hitPoints = obj._hitPoints;
	_energyPoints = obj._energyPoints;
	_attackDamage = obj._attackDamage;
	return (*this);
}

void	FragTrap::highFiveGuys( void ) {
	std::cout << "FragTrap " << _name << "raised his hands to high five his friends" << std::endl;
}