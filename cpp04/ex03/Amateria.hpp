#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "Character.hpp"

class Amateria{
	protected:
		std::string _type;
	public:
		Amateria();
		Amateria( const Amateria& obj);
		Amateria& operator=( const Amateria& obj);
		~Amateria();
		Amateria(std::string const& type);
		std::string const& getType() const;
		void	setType( std::string new_type );
		virtual Amateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif