#include "AMateria.hpp"

AMateria::AMateria() {
	// std::cout << "AMateria Constructor Called" << std::endl;
}


AMateria::AMateria( const AMateria& obj ) {
	// std::cout << "AMateria Copy Constructor Called" << std::endl;
	*this = obj;
}

AMateria& AMateria::operator=( const AMateria& obj) {
	(void)obj;
	return (*this);
}

AMateria::~AMateria() {
	// std::cout << "AMateria Destructor Called" << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type) {
}

std::string const& AMateria::getType() const {
	return _type;
}

void	AMateria::use( ICharacter& target ) {
	(void)target;
}