#include "Zombie.hpp"

Zombie::Zombie( std::string name ) {
	std::cout << "Zombie: " << name << " was created" << std::endl;
	_name = name;
	announce();
}

Zombie::~Zombie( void ) {
	std::cout << _name << " was destroyed" << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}