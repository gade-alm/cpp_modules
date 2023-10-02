#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {;
	// std::cout << "Ice Constructor Called" << std::endl;
}

Ice::Ice( const Ice& obj ) : AMateria("ice") {
	// std::cout << "Ice copy Constructor called" << std::endl;
	*this = obj;
}

Ice::~Ice() {
	// std::cout << "Ice Destructor Called" << std::endl;
}

Ice& Ice::operator=( const Ice& obj ) {
	(void) obj;
	return (*this);
}

AMateria* Ice::clone() const {
	AMateria* ice = new Ice;

	return (ice);
}

void	Ice::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}
