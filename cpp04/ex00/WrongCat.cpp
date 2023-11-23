#include "WrongCat.hpp"

# define RESET   "\033[0m"
# define MAGENTA "\033[35m"      /* Magenta */

WrongCat::WrongCat( void ) {
	_type = "WrongCat";
	std::cout << MAGENTA << "WrongCat Default Constructor Called" << RESET << std::endl;
}

WrongCat::~WrongCat( void ) {
	std::cout << MAGENTA << "WrongCat Default destructor called" << RESET << std::endl;
}

WrongCat::WrongCat ( const WrongCat& obj) : WrongAnimal() {
	std:: cout << MAGENTA << "WrongCat copy constructor called" << RESET << std::endl;
	*this = obj;
}

WrongCat& WrongCat::operator=( const WrongCat& obj) {
	std::cout << MAGENTA << "WrongCat assignment overload called" << RESET << std::endl;
	_type = obj._type;
	return (*this);
}

void	WrongCat::makeSound( void ) const {
	std::cout << MAGENTA << "Mooooo" << RESET << std::endl;
}