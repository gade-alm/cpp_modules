#include "AAnimal.hpp"

AAnimal::AAnimal( void ) {
	_type = "Animal";
	std::cout << RED << "Animal Default Constructor Called" << RESET << std::endl;
}

AAnimal::~AAnimal( void ) {
	std::cout << RED << "Animal Default destructor called" << RESET << std::endl;
}

AAnimal::AAnimal ( const AAnimal& obj ) {
	std:: cout << RED << "Animal copy constructor called" << RESET << std::endl;
	*this = obj;
}

AAnimal& AAnimal::operator=( const AAnimal& obj ) {
	std::cout << RED << "Animal assignment overload called" << RESET << std::endl;
	_type = obj._type;
	return (*this);
}

std::string	AAnimal::getType( void ) const {
	return (this->_type);
}
