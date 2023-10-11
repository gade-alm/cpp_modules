#include "Cat.hpp"

Cat::Cat( void ) {
	_type = "Cat";
	std::cout << YELLOW << "Cat Default Constructor Called" << RESET << std::endl;
}

Cat::~Cat( void ) {
	std::cout << YELLOW << "Cat Default destructor called" << RESET << std::endl;
}

Cat::Cat ( const Cat& obj) :Animal() {
	std:: cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
	*this = obj;
}

Cat& Cat::operator=( const Cat& obj) {
	std::cout << YELLOW << "Cat assignment overload called" << RESET << std::endl;
	_type = obj._type;
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << YELLOW << "Miau" << RESET << std::endl;
}