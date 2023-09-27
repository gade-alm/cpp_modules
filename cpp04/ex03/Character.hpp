#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter { 
	private:
		std::string const _name;
		AMateria*	_inventory[4];
	public:
		Character();
		Character( std::string const& name );
		Character( const Character& obj );
		Character& operator=( const Character& obj );
		~Character();

		virtual std::string const & getName() const;
		virtual void 				equip(AMateria* m);
		virtual void 				unequip(int idx);
		virtual void 				use(int idx, ICharacter& target);
};

#endif