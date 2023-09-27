#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_materiasInventory[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (_materiasInventory[i])
			delete _materiasInventory[i];
}

MateriaSource::MateriaSource( const MateriaSource& obj ) { 
	for (int i = 0; i < 4; i++)
		_materiasInventory[i] = NULL;
	*this = obj;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& obj ) {
	
	return (*this);
}

void	MateriaSource::learnMateria( AMateria* ) {
	
}

AMateria* MateriaSource::createMateria( std::string const & type ) {

}