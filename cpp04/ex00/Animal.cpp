#include "Animal.hpp"

Animal::Animal( void ) {
	_type = "Animal";
	std::cout << RED << "Animal Default Constructor Called" << RESET << std::endl;
}

Animal::~Animal( void ) {
	std::cout << RED << "Animal Default destructor called" << RESET << std::endl;
}

Animal::Animal ( const Animal& obj) {
	std:: cout << RED << "Animal copy constructor called" << RESET << std::endl;
	*this = obj;
}

Animal& Animal::operator=( const Animal& obj) {
	std::cout << RED << "Animal assignment overload called" << RESET << std::endl;
	_type = obj._type;
	return (*this);
}

std::string	Animal::getType( void ) const {
	return (this->_type);
}

void	Animal::makeSound( void ) const {
	std::cout << RED << "No sound" << RESET << std::endl;
}