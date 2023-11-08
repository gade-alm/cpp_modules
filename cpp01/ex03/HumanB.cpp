#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {
		std::cout << "HumanB: " << _name << " was created without any weapon" << std::endl;
}

HumanB::~HumanB( void ) {
	std::cout << "Default HumanB destructor called" << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon ) {
	_weapon = &weapon;
	std::cout << _name << " equipped a " << _weapon->getType() << std::endl;
}

void	HumanB::attack( void ) { 
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their hands" << std::endl;
}