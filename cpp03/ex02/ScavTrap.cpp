#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	_guardGate = 0;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) {
	_name = name;
	_guardGate = 0;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name <<  " Constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& obj ) : ClapTrap() {
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

void	ScavTrap::guardGate() {
	if (_guardGate == 0) {
		std::cout << "ScavTrap is now in Gate Keeper mode" << std::endl;
		_guardGate = 1;
		return ;
	}
	else
		std::cout << "ScavTrap already is in Gate Keeper mode" << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {
	if (this->_energyPoints < 1) {
		std::cout << RED << "ScavTrap " << this->_name << " energy points is " << this->_energyPoints << " and it can't act!" << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
	takeDamage( this->_attackDamage );
	this->_energyPoints--;
}