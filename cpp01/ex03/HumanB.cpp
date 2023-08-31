#include <HumanB.hpp>


HumanB::HumanB(std::string name){
	_name = name;
}

HumanB::~HumanB() {
	std::cout << "Default HumanB destructor called" << std::endl;
}

void	HumanB::setWeapon(std::string weapon) {
	_weapon = weapon;
}