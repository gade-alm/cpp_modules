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

std::string	const& Character::getName()  const{
	return _name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			std::cout << "Materia equipped successfully!" << std::endl;
			return ;
		}
	}
	std::cout << "Full inventory, can't equip new materia" << std::endl;
}

void	Character::unequip( int idx ) {
	if (idx > -1 && idx < 4) {
		if (_inventory[idx] != NULL)
			_inventory[idx] = NULL;
		else
		std::cout << "No materia equipped on the slot" << std::endl;
	}
	else
		std::cout << "Invalid slot number, please try again" << std::endl;
}

void	Character::use( int idx, ICharacter& target ) { 
	if (idx > -1 && idx < 4) {
		if (_inventory[idx] != NULL)
			_inventory[idx]->use(target);
	}
	else
		std::cout << "Invalid slot number, please try again" << std::endl;
}
