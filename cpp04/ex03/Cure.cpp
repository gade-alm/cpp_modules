#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure Constructor Called" << std::endl;
}

Cure::Cure( const Cure& obj ) : AMateria("cure") {
	// std::cout << "Cure copy Constructor called" << std::endl;
	*this = obj;
}

Cure::~Cure() {
	// std::cout << "Cure Destructor Called" << std::endl;
}

Cure& Cure::operator=( const Cure& obj ) {
	(void) obj;
	return (*this);
}

AMateria* Cure::clone() const {
	AMateria* cure = new Cure;

	return (cure);
}

void	Cure::use( ICharacter& target) {
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
