#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource { 
	protected:
		AMateria* _materiasInventory[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource( const MateriaSource& obj );
		MateriaSource& operator=( const MateriaSource& obj );
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};

#endif