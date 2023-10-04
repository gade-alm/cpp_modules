#include "DiamondTrap.hpp"

/* FragtrapHP 100
ScavTrapEN 50
FragTrapAD 30
ScavTrapAttack function*/

DiamondTrap::DiamondTrap( void ) {
	_name = "";
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::hp;
	_attackDamage = FragTrap::ad;
	_energyPoints = ScavTrap::ep;
	std::cout << GREEN << "DiamondTrap Default constructor called" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << GREEN << "DiamondTrap Default destructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name") {
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::hp;
	_attackDamage = FragTrap::ad;
	_energyPoints = ScavTrap::ep;
	std::cout << GREEN << "DiamondTrap Name Constructor Called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap ( const DiamondTrap& obj ) : ClapTrap(), FragTrap(), ScavTrap(){
	std::cout << GREEN << "DiamondTrap copy constructor called" << RESET << std::endl;
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& obj) {
	std::cout << "DiamondTrap Assignment Overload called" << std::endl;
	ClapTrap::_name = obj._name;
	this->_name = obj._name;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	this->_hitPoints = obj._hitPoints;
	return (*this);
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << "DiamondTrap hitpoints(100): " << DiamondTrap::_hitPoints << std::endl;
	std::cout << "DiamondTrap energyPoints(50): " << DiamondTrap::_energyPoints << std::endl;
	std::cout << "DiamondTrap attackDamage(30): " << DiamondTrap::_attackDamage << std::endl;
	std::cout << "DiamondTrap name is: " << DiamondTrap::_name << std::endl;
	std::cout << "DiamondTrap ClapTrap name is: " << ClapTrap::_name << std::endl;
}

