#include <Weapon.hpp>

std::string	Weapon::getType() {
	return _type; 
}

std::string Weapon::setType(std::string new_weapon) {
	_type = new_weapon;
}

Weapon::Weapon(std::string name) {
	_type = name;
}

Weapon::~Weapon() {
}
