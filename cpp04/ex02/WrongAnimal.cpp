#include "WrongAnimal.hpp"

# define RESET   "\033[0m"
# define CYAN    "\033[36m"      /* Cyan */

WrongAnimal::WrongAnimal( void ) {
	_type = "Wrong Animal"; 
	std::cout << CYAN << "WrongAnimal Constructor Called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& obj ) {
	std::cout << CYAN << "WrongAnimal Copy Constructor Called" << RESET << std::endl;
	*this = obj;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& obj ) {
	std::cout << CYAN << "WrongAnimal Assignment operator called" << RESET << std::endl;
	_type = obj._type;
	return (*this);
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << CYAN << "WrongAnimal destructor called" << RESET << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << CYAN << "WrongAnimal Sound" << RESET << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}