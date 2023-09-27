#include "Character.hpp"

Character::Character() :  _name("Gabriel") {
	for (int i = 0; i < 4; i++) 
		_inventory[i] = NULL;
}

Character::Character( std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++) 
		_inventory[i] = NULL;
}

Character::Character( const Character& obj) {
	for (int i = 0; i < 4; i++) 
		_inventory[i] = NULL;
	*this = obj;
}

Character& Character::operator=( const Character& obj ) {
	for (int i = 0; i < 4; i++) 
		_inventory[i] = NULL;
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

