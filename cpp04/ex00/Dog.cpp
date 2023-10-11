#include "Dog.hpp"

Dog::Dog( void ) {
	this->_type = "Dog";
	std::cout << BLUE << "Dog Default Constructor Called" << RESET << std::endl;
}

Dog::~Dog( void ) {
	std::cout << BLUE << "Dog Default destructor called" << RESET << std::endl;
}

Dog::Dog ( const Dog& obj) : Animal(){
	std:: cout << BLUE << "Dog copy constructor called" << RESET << std::endl;
	*this = obj;
}

Dog& Dog::operator=( const Dog& obj ) {
	std::cout << BLUE << "Dog assignment overload called" << RESET << std::endl;
	_type = obj._type;
	return (*this);
}

void	Dog::makeSound( void ) const {
	std::cout << BLUE << "Woof woof" << RESET << std::endl;
}
