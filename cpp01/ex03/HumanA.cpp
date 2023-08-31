#include <HumanA.hpp>
#include <iostream>
#include <Weapon.hpp>

HumanA::HumanA(std::string name, Weapon weapon) {
	_name = name;
}

HumanA::~HumanA() {
	std::cout << "Default HumanA destructor called" << std::endl;
}

void	HumanA::attack() {
	std::cout << _name << "attacks with their" << _weapon << std::endl;
}