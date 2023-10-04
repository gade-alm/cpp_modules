#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	std::cout << YELLOW << "Cat Default Constructor Called" << RESET << std::endl;
}

Cat::~Cat() {
	std::cout << YELLOW << "Cat Default destructor called" << RESET << std::endl;
}

Cat::Cat ( const Cat& obj) :Animal() {
	std:: cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
	*this = obj;
}

Cat& Cat::operator=( const Cat& obj) {
	_type = obj._type;
	std::cout << YELLOW << "Cat assignment overload called" << RESET << std::endl;
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << YELLOW << "Miau" << RESET << std::endl;
}