#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
}

MateriaSource::~MateriaSource() {
}

MateriaSource::MateriaSource( const MateriaSource& obj ) { 
	*this = obj;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& obj ) {
	
	return (*this);
}

void	MateriaSource::learnMateria( AMateria* ) {

}

AMateria* MateriaSource::createMateria( std::string const & type ) {
	
}