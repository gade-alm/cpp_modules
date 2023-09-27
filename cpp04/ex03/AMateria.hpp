#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria{
	protected:
		std::string		const _type;
	public:
		AMateria();
		AMateria( const AMateria& obj);
		AMateria& operator=( const AMateria& obj);
		~AMateria();

		AMateria(std::string const & type);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif