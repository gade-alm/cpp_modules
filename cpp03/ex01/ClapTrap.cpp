#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Claptrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Default destructor called" << std::endl;
}

ClapTrap::ClapTrap ( const ClapTrap& obj ) : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& obj) {
	std::cout << "ClapTrap assignment overload called" << std::endl;
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	return (*this);
}

void	ClapTrap::attack( const std::string& target) {
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
