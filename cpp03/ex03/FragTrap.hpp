#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap( void );
		~FragTrap( void );
		FragTrap( const FragTrap& obj );
		FragTrap( std::string name );
		FragTrap& operator=( const FragTrap& obj );
		void	highFiveGuys( void );

		static const int	hp = 100;
		static const int	ad = 30;
};

#endif