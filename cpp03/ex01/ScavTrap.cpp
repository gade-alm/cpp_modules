#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : {
	_guardGate = 0;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& obj ) {
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& obj ) {
	std::cout << "Scavtrap assignment overload called" << std::endl;
	*this = obj;
	return (*this);
}

ScavTrap::ScavTrap( std::string name ) {
	
}

void	ScavTrap::guardGate() {
	if (_guardGate == 0) {
		std::cout << "ScavTrap is now in Gate Keeper mode" << std::endl;
		_guardGate = 1;
		return ;
	}
	else
		std::cout << "ScavTrap already is in Gate Keeper mode" << std::endl;
}