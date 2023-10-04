#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << MAGENTA << "Claptrap Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << MAGENTA << "ClapTrap " << name << " constructor called" << RESET <<std::endl;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << MAGENTA << "ClapTrap Default destructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap ( const ClapTrap& obj ) : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << MAGENTA << "ClapTrap Copy constructor called" << RESET <<std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& obj ) {
	std::cout << MAGENTA << "ClapTrap Assignment overload called" << RESET << std::endl;
	this->_name = obj._name;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	this->_hitPoints = obj._hitPoints;
	return (*this);
}

void	ClapTrap::attack( const std::string& target ) {
	if (this->_energyPoints < 1) {
		std::cout << RED << "ClapTrap " << this->_name << " energy points is " << this->_energyPoints << " and it can't act!" << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
	takeDamage( this->_attackDamage );
	this->_energyPoints--;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (this->_hitPoints - amount > 0) {
		std::cout << this->_name << " took " << amount << " of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
	else
		std::cout << "ClapTrap " << this->_name << "is already dead💀" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_energyPoints < 1) {
		std::cout << RED << "ClapTrap " << this->_name << " energy points is " << this->_energyPoints << " and it can't act!" << RESET << std::endl;
		return ;
	}
	if (this->_hitPoints < 1) {
		std::cout << RED << "ClapTrap " << this->_name << "is already dead💀" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "ClapTrap " << this->_name << " just healed " << amount << RESET << std::endl;
	this->_hitPoints+= amount;
	this->_energyPoints--;
}
