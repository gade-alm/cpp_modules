#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	_name = "";
	ClapTrap::_name = "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Default destructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) {
	_name = name;
	ClapTrap::_name = ClapTrap::_name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Name Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap ( const DiamondTrap& obj ) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
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

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap hitpoints: " << DiamondTrap::_hitPoints << std::endl;
	std::cout << "DiamondTrap energyPoints: " << DiamondTrap::_energyPoints << std::endl;
	std::cout << "DiamondTrap attackDamage: " << DiamondTrap::_attackDamage << std::endl;
	std::cout << "DiamondTrap name is: " << DiamondTrap::_name << std::endl;
	std::cout << "DiamondTrap ClapTrap name is: " << ClapTrap::_name << std::endl;
}

