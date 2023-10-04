#include "Weapon.hpp"

std::string	Weapon::getType( void ) {
	return _type; 
}

void	Weapon::setType( std::string new_weapon ) {
	_type = new_weapon;
}

Weapon::Weapon( std::string name ) : _type( name ) {
}

Weapon::~Weapon( void ) {
}
