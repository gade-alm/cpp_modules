#ifndef WEAPON_H
# define WEAPON_H
#include <string>

class Weapon{
	private:
		std::string		_type;
	public:
		Weapon( std::string weapon );
		~Weapon( void );
		std::string	getType( void );
		void		setType( std::string new_weapon );
};

#endif