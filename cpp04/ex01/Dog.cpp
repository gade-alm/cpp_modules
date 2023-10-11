#include "Dog.hpp"

Dog::Dog( void ) {
	_type = "Dog";
	_brain = new Brain();
	std::cout << BLUE << "Dog Default Constructor Called" << RESET << std::endl;
}

Dog::~Dog( void ) {
	std::cout << BLUE << "Dog Default destructor called" << RESET << std::endl;
	delete _brain;
}

Dog::Dog ( const Dog& obj) : Animal(){
	std:: cout << BLUE << "Dog copy constructor called" << RESET << std::endl;
	_type = "Dog";
	_brain = new Brain();
	*this = obj;
}

Dog& Dog::operator=( const Dog& obj ) {
	_type = obj._type;
	std::cout << BLUE << "Dog assignment overload called" << RESET << std::endl;
	return (*this);
}

void	Dog::makeSound( void ) const {
	std::cout << BLUE << "Woof woof" << RESET << std::endl;
}
