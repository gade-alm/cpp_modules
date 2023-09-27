#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : IMateriaSource { 
	private:
		AMateria *_materiasInventory[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource( const MateriaSource& obj );
		MateriaSource& operator=( const MateriaSource& obj );
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif