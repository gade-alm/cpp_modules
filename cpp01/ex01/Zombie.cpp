#include "Zombie.hpp"

Zombie::Zombie(){
};

Zombie::~Zombie(){
	std::cout << _name << " was destroyed" << std::endl;
};

void	Zombie::announce() {
	std::cout << _name << ':' <<  "BraiiiiiiinnnzzzZ..." << std::endl;
};

void	Zombie::set_name(std::string name){
	_name = name;
}