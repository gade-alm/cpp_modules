#include "Amateria.hpp"

Amateria::Amateria() {
	std::cout << "Amateria Constructor Called" << std::endl;
}

Amateria::~Amateria() {
	std::cout << "Amateria Destructor Called" << std::endl;
}

Amateria::Amateria( const Amateria& obj ) {
	std::cout << "Amateria Copy Constructor Called" << std::endl;
	*this = obj;
}

Amateria& Amateria::operator=( const Amateria& obj) {
	return (*this);
}

void	Amateria::setType( std::string new_type ) {
	_type = new_type;
}

std::string const& Amateria::getType() const {
	return _type;
}