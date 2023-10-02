#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_materiasInventory[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (_materiasInventory[i] != NULL)
			delete _materiasInventory[i];
}

MateriaSource::MateriaSource( const MateriaSource& obj ) { 
	for (int i = 0; i < 4; i++)
		_materiasInventory[i] = obj._materiasInventory[i];
}

MateriaSource& MateriaSource::operator=( const MateriaSource& obj ) {
	for (int i = 0; i < 4; i++)
	{
		if (_materiasInventory[i] == NULL)
			_materiasInventory[i] = obj._materiasInventory[i];
		else
			delete _materiasInventory[i];
	}
	return (*this);
}

void	MateriaSource::learnMateria( AMateria* materia ) {
	for (int i = 0; i < 4 && materia != NULL; i++)
	{
		if (_materiasInventory[i] == NULL) {
			_materiasInventory[i] = materia;
			std::cout << "New materia learned" << std::endl;
			return ;
		}
		if (i >= 3) {
		std::cout << "No slots to learn new materias" << std::endl;
		delete materia;
		return ;
		}
	}
	std::cout << "Can't create materia with this name, check again" << std::endl;
	delete materia;
}

AMateria* MateriaSource::createMateria( std::string const & type ) {
	for (int i = 0; i < 4; i++)
	{
		if (_materiasInventory[i] != NULL && _materiasInventory[i]->getType() == type)
		{
			std::cout << "Materia " << type << " created" << std::endl;
			return _materiasInventory[i]->clone();
		}
	}
	std::cout << "No materia with " << type << " name" << std::endl;
	return 0;
}