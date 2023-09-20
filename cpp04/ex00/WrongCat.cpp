#include "WrongCat.hpp"

WrongCat::WrongCat() {
	_type = "WrongCat";
	std::cout << GREEN << "WrongCat Default Constructor Called" << RESET << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << GREEN << "WrongCat Default destructor called" << RESET << std::endl;
}

WrongCat::WrongCat ( const WrongCat& obj) :Animal() {
	std:: cout << GREEN << "WrongCat copy constructor called" << RESET << std::endl;
	*this = obj;
}

WrongCat& WrongCat::operator=( const WrongCat& obj) {
	_type = obj._type;
	std::cout << GREEN << "WrongCat assignment overload called" << RESET << std::endl;
	return (*this);
}

void	WrongCat::makeSound( void ) const {
	std::cout << GREEN << "Mooooo" << RESET << std::endl;
}