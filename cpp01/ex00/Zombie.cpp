#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	announce();
};

Zombie::~Zombie()
{
	std::cout << name << " was destroyed" << std::endl;
};

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}