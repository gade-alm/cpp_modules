#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : _name(name), _weapon(&weapon){
}

HumanA::~HumanA( void ) {
	std::cout << "Default HumanA destructor called" << std::endl;
}

void	HumanA::attack( void ) {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
