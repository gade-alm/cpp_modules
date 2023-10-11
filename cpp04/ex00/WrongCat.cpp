#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {
	_type = "WrongCat";
	std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat Default destructor called" << std::endl;
}

WrongCat::WrongCat ( const WrongCat& obj) : WrongAnimal() {
	std:: cout << "WrongCat copy constructor called" << std::endl;
	*this = obj;
}

WrongCat& WrongCat::operator=( const WrongCat& obj) {
	std::cout << "WrongCat assignment overload called" << std::endl;
	_type = obj._type;
	return (*this);
}

void	WrongCat::makeSound( void ) const {
	std::cout << "Mooooo" << std::endl;
}