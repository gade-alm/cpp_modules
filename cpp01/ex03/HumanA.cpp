#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : _name(name), _weapon(&weapon){
	std::cout << "HumanA: " << _name << " was created holding the weapon: " << _weapon->getType() << std::endl;
}

HumanA::~HumanA( void ) {
	std::cout << "Default HumanA destructor called" << std::endl;
}

void	HumanA::attack( void ) {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
